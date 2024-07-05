#include "helper.h"

unordered_map<string, sort_function_pointer> pure_func = 
{
    {"flash-sort", flash_sort},
    {"bubble-sort", bubble_sort},
    {"quick-sort", quick_sort},
    {"insertion-sort", insertion_sort},
    {"shell-sort", shell_sort},
    {"radix-sort", radix_sort},
    {"counting-sort", counting_sort},
    {"heap-sort", heap_sort},
    {"selection-sort", selection_sort},
    {"merge-sort", merge_sort},
    {"shaker-sort", shaker_sort}
};

unordered_map<string, comp_count_sort_function_pointer> comparison_count_func = 
{
    {"flash-sort", flash_sort_compare},
    {"bubble-sort", bubble_sort_compare},
    {"quick-sort", quick_sort_compare},
    {"insertion-sort", insertion_sort_compare},
    {"shell-sort", shell_sort_compare},
    {"radix-sort", radix_sort_compare},
    {"counting-sort", counting_sort_compare},
    {"heap-sort", heap_sort_compare},
    {"selection-sort", selection_sort_compare},
    {"merge-sort", merge_sort_compare},
    {"shaker-sort", shaker_sort_compare}
};

unordered_map<string, string> order_name_from_flag = 
{
    {"-rand", "Randomized"},
    {"-nsorted", "Nearly Sorted"},
    {"-sorted", "Sorted"},
    {"-rev", "Reversed"}
};

unordered_map<string, int> data_type = 
{
    {"Randomized", 0},
    {"Nearly Sorted", 1},
    {"Sorted", 2},
    {"Reversed", 3}
};

unordered_map<string, string> flag_to_name = 
{
    {"flash-sort", "Flash sort"},
    {"bubble-sort", "Bubble sort"},
    {"quick-sort", "Quick sort"},
    {"insertion-sort", "Insertion sort"},
    {"shell-sort", "Shell sort"},
    {"radix-sort", "Radix sort"},
    {"counting-sort", "Counting sort"},
    {"heap-sort", "Heap sort"},
    {"selection-sort", "Selection sort"},
    {"merge-sort", "Merge sort"},
    {"shaker-sort", "Shaker sort"}
};

void get_input_from_file(string input, int *&a, int &n)
{
    ifstream fin(input);
    if(!fin)
    {
        cout << "Input file error\n";
        return;
    }

    fin >> n;
    a = new int [n];
    for(int i = 0; i < n; i++)
        fin >> a[i];

    fin.close();
}

void write_data_to_file(string output, int *a, int n, bool append)
{
    ofstream fout;
    if(append)
        fout.open(output, ios::app);
    else
        fout.open(output, ios::trunc);
    if(!fout)
    {
        cout << "Output file error\n";
        return;
    }

    fout << n << '\n';
    for(int i = 0; i < n; i++)
        fout << a[i] << " ";
    fout << '\n';

    fout.close();
}

void command1(string algo_name, int n, int param_mask, string input_file) // one algo one array from input file
{
    cout << "Command1 activated!\n";

    // Initiate array
    int *a;
    get_input_from_file(input_file, a, n);
    sort_function_pointer sort = pure_func[algo_name]; 

    int *b = new int [n];
    copy(a, a + n, b);

    // Sort and record running time + number of comparisons
    chrono::time_point start = chrono::steady_clock::now();
    sort(b, n);
    chrono::time_point stop = chrono::steady_clock::now();

    chrono::milliseconds duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    copy(a, a + n, b);
    long long num_compare = 0;
    comp_count_sort_function_pointer comp_count_sort = comparison_count_func[algo_name];
    comp_count_sort(b, n, num_compare);

    // Print info
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << flag_to_name[algo_name] << '\n';
    cout << "Input file: " << input_file << '\n';
    cout << "Input size: " << n << '\n';
    cout << "------------------------\n";
    
    if(is_on(param_mask, 0)) // 0th bit is up -> shows runtime
        cout << "Running time: " << duration.count() << " milliseconds\n";
    if(is_on(param_mask, 1)) // 1th bit is up -> shows number of comparison
        cout << "Comparisons: " << num_compare << " times\n";

    // Write data to file
    write_data_to_file("output.txt", b, n, false);

    // Remember to delete these babies
    delete [] a;
    delete [] b;
}

void command2(string algo_name, int n, int param_mask, string input_order) // one algo one array generated
{
    cout << "Command2 activated!\n";
    // Initiate array
    int *a = new int[n];
    int order = data_type[input_order];
    GenerateData(a, n, order);
    sort_function_pointer sort = pure_func[algo_name]; 

    int *b = new int [n];
    copy(a, a + n, b);

    // Sort and record running time + number of comparisons
    chrono::time_point start = chrono::steady_clock::now();
    sort(b, n);
    chrono::time_point stop = chrono::steady_clock::now();
    chrono::milliseconds duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    copy(a, a + n, b);
    long long num_compare = 0;
    comp_count_sort_function_pointer comp_count_sort = comparison_count_func[algo_name];
    comp_count_sort(b, n, num_compare);

    // Print info
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << flag_to_name[algo_name] << '\n';
    cout << "Input size: " << n << '\n';
    cout << "Input order: " << input_order << '\n';
    cout << "------------------------\n";
    
    if(is_on(param_mask, 0)) // 0th bit is up -> shows runtime
        cout << "Running time: " << duration.count() << " milliseconds\n";
    if(is_on(param_mask, 1)) // 1th bit is up -> shows number of comparison
        cout << "Comparisons: " << num_compare << " times\n";

    // Write data to file
    write_data_to_file("input.txt", a, n, false);

    // Remember to delete these babies
    delete [] a;
    delete [] b;
}

void command3(string algo_name, int n, int param_mask) // one algo one array for each data arrangements generated
{
    cout << "Command3 activated!\n";
    // Initiate array
    int *a = new int[n];
    int *b = new int [n];
    sort_function_pointer sort = pure_func[algo_name]; 
    comp_count_sort_function_pointer comp_count_sort = comparison_count_func[algo_name];

    chrono::milliseconds duration[4];
    long long num_compare[4] = {0};

    // Sort and record running time + number of comparisons
    for(int i = 0; i < 4; i++)
    {
        GenerateData(a, n, i);
        copy(a, a + n, b);
        chrono::time_point start = chrono::steady_clock::now();
        sort(b, n);
        chrono::time_point stop = chrono::steady_clock::now();

        duration[i] = chrono::duration_cast<chrono::milliseconds>(stop - start);

        copy(a, a + n, b);
        comp_count_sort(b, n, num_compare[i]);
        
        // Write data to file
        write_data_to_file("input_" + to_string(i + 1) + ".txt", a, n, false);
    }

    // Print info
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << flag_to_name[algo_name] << '\n';
    cout << "Input size: " << n << '\n';

    string input_order[4] = {"Randomized", "Nearly sorted", "Sorted", "Reversed"};

    for(int i = 0; i < 4; i++)
    {
        cout << '\n';
        cout << "Input order: " << input_order[i] << '\n';
        cout << "------------------------\n";
    
        if(is_on(param_mask, 0)) // 0th bit is up -> shows runtime
            cout << "Running time: " << duration[i].count() << " milliseconds\n";
        if(is_on(param_mask, 1)) // 1th bit is up -> shows number of comparison
            cout << "Comparisons: " << num_compare[i] << " times\n";
    }
    
    // Remember to delete these babies
    delete [] a;
    delete [] b;
}

void command4(string algo_name1, string algo_name2, int n, int param_mask, string input_file) // two algos one array from input file
{
    cout << "Command4 activated!\n";

    // Initiate array
    int *a;
    get_input_from_file(input_file, a, n);
    sort_function_pointer sort1 = pure_func[algo_name1]; 
    sort_function_pointer sort2 = pure_func[algo_name2];
    int *b = new int [n];

    // Sort and record running time + number of comparisons 
    copy(a, a + n, b);
    chrono::time_point start = chrono::steady_clock::now();
    sort1(b, n);
    chrono::time_point stop = chrono::steady_clock::now();
    chrono::milliseconds duration1 = chrono::duration_cast<chrono::milliseconds>(stop - start);

    copy(a, a + n, b);
    start = chrono::steady_clock::now();
    sort2(b, n);
    stop = chrono::steady_clock::now();
    chrono::milliseconds duration2 = chrono::duration_cast<chrono::milliseconds>(stop - start);

    long long num_compare1 = 0, num_compare2 = 0;
    comp_count_sort_function_pointer comp_count_sort1 = comparison_count_func[algo_name1];
    comp_count_sort_function_pointer comp_count_sort2 = comparison_count_func[algo_name2];

    copy(a, a + n, b);
    comp_count_sort1(b, n, num_compare1);
    copy(a, a + n, b);
    comp_count_sort2(b, n, num_compare2);

    // Print info
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << flag_to_name[algo_name1] << " | " << flag_to_name[algo_name2] << '\n';
    cout << "Input file: " << input_file << '\n';
    cout << "Input size: " << n << '\n';
    cout << "------------------------\n";
    
    if(is_on(param_mask, 0)) // 0th bit is up -> shows runtime
        cout << "Running time: " << duration1.count() << " milliseconds" << " | " << duration2.count() << " milliseconds\n";
    if(is_on(param_mask, 1)) // 1th bit is up -> shows number of comparison
        cout << "Comparisons: " << num_compare1 << " times" << " | " << num_compare2 << " times\n";

    // Write data to file
    write_data_to_file("output.txt", b, n, false);

    // Remember to delete these babies
    delete [] a;
    delete [] b;
}

void command5(string algo_name1, string algo_name2, int n, int param_mask, string input_order) // two algos one array generated
{
    cout << "Command5 activated!\n";
    // Initiate array
    int *a = new int[n];
    int order = data_type[input_order];
    GenerateData(a, n, order);
    sort_function_pointer sort1 = pure_func[algo_name1]; 
    sort_function_pointer sort2 = pure_func[algo_name2];
    int *b = new int [n];

    // Sort and record running time + number of comparisons
    copy(a, a + n, b);
    chrono::time_point start = chrono::steady_clock::now();
    sort1(b, n);
    chrono::time_point stop = chrono::steady_clock::now();
    chrono::milliseconds duration1 = chrono::duration_cast<chrono::milliseconds>(stop - start);

    copy(a, a + n, b);
    start = chrono::steady_clock::now();
    sort2(b, n);
    stop = chrono::steady_clock::now();
    chrono::milliseconds duration2 = chrono::duration_cast<chrono::milliseconds>(stop - start);

    long long num_compare1 = 0, num_compare2 = 0;
    comp_count_sort_function_pointer comp_count_sort1 = comparison_count_func[algo_name1];
    comp_count_sort_function_pointer comp_count_sort2 = comparison_count_func[algo_name2];

    copy(a, a + n, b);
    comp_count_sort1(b, n, num_compare1);
    copy(a, a + n, b);
    comp_count_sort2(b, n, num_compare2);

    // Print info
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << flag_to_name[algo_name1] << " | " << flag_to_name[algo_name2] << '\n';
    cout << "Input size: " << n << '\n';
    cout << "Input order: " << input_order << '\n';
    cout << "------------------------\n";
    
    if(is_on(param_mask, 0)) // 0th bit is up -> shows runtime
        cout << "Running time: " << duration1.count() << " milliseconds" << " | " << duration2.count() << " milliseconds\n";
    if(is_on(param_mask, 1)) // 1th bit is up -> shows number of comparison
        cout << "Comparisons: " << num_compare1 << " times" << " | " << num_compare2 << " times\n";

    // Write data to file
    write_data_to_file("input.txt", a, n, false);

    // Remember to delete these babies
    delete [] a;    
    delete [] b;
}

void algorithm_mode(const vector<string> &arglist)
{
    // Generate/get data, indicate sorting algorithm and output parameters
    string algo = arglist[0];
    string input_order;
    string input_file;
    int n;
    int param_mask = 0;

    switch(arglist.size())
    {
        case 3:
            if(arglist[2] == "-time")
                param_mask = 1;
            else if(arglist[2] == "-comp")
                param_mask = 2;
            else 
                param_mask = 3;

            if(arglist[1].find('.') != string::npos) // a dot '.' exists in arglist[1] -> input file
            {
                input_file = arglist[1];
                command1(algo, n, param_mask, input_file);
            }
            else
            {
                n = stoi(arglist[1]);
                command3(algo, n, param_mask);
            }
            break;

        case 4:
            if(arglist[3] == "-time")
                param_mask = 1;
            else if(arglist[3] == "-comp")
                param_mask = 2;
            else 
                param_mask = 3;

            n = stoi(arglist[1]);
            input_order = order_name_from_flag[arglist[2]];
            command2(algo, n, param_mask, input_order);
            break;

        default:
            break;
    }
}

void comparison_mode(const vector<string> &arglist)
{
    string algo1 = arglist[0];
    string algo2 = arglist[1];
    string input_file;
    string input_order;
    int n;

    switch(arglist.size())
    {
        case 3:
            input_file = arglist[2];
            command4(algo1, algo2, n, 3, input_file);
            break;
        
        case 4:
            n = stoi(arglist[2]);
            input_order = order_name_from_flag[arglist[3]];
            command5(algo1, algo2, n, 3, input_order);
            break;

        default:
            break;
    }
}

bool is_on(int n, int i)
{
    return (n & (1 << i));
}