#pragma once

#include <chrono>
#include <string>
#include <vector>
#include <unordered_map>

#include "SortingAlgorithm.h"
#include "DataGenerator.h"

using namespace std;

using sort_function_pointer = void (*)(int [], int);
using comp_count_sort_function_pointer = void (*)(int [], int, long long &);

extern unordered_map<string, sort_function_pointer> pure_func;
extern unordered_map<string, comp_count_sort_function_pointer> comparison_count_func;
extern unordered_map<string, int> data_type;

void get_input_from_file(string input, int *&a, int &n);
void write_data_to_file(string output, int *a, int n, bool append);
void command1(string algo_name, int n, int param_mask, string input_file);
void command2(string algo_name, int n, int param_mask);
void command3(string algo_name, int n, int param_mask);
void command4(string algo_name1, string algo_name2, int n, int param_mask, string input_file);
void command5(string algo_name1, string algo_name2, int n, int param_mask);
void algorithm_mode(const vector<string> &arglist);
void comparison_mode(const vector<string> &arglist);

bool is_on(int n, int i);