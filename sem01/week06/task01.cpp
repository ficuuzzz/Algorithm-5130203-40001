#include <iostream>

using namespace std;

int* allocate_memory(int n);
int** allocate_matrix(int n);
void print_vector(int n, int* x);
void input_matrix(int n, int **x);
void print_matrix(int n, int **x);
void calculate_sum_rows(int n, int **x, int * sum_rows);
void calculate_sum_columns(int n, int **x, int * sum_columns);

int main() {
    int n, **a, *sum_rows, *sum_columns;
    cin >> n;

    a = allocate_matrix(n);
    sum_rows = allocate_memory(n);
    sum_columns = allocate_memory(n);

    input_matrix(n, a);

    calculate_sum_rows(n, a, sum_rows);

    calculate_sum_columns(n, a, sum_columns);

    cout << "Sum of rows = " << endl;
    
    print_matrix(n, a);

    cout << "Sum of every row = " << endl;

    print_vector(n, sum_rows);

    cout << "Sum of every column = " << endl;

    print_vector(n, sum_columns);

    return 0;
}

int* allocate_memory(int n) {
	return (int*)malloc(n * sizeof(int));
}

int** allocate_matrix(int n) {
	int ** m = (int**)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        m[i] = (int*)malloc(n * sizeof(int));
    }
    return m;
}

void print_vector(int n, int* x) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void input_matrix(int n, int **x){
    for (int i = 0; i < n; i++) {
        cout << "Row: " << i << endl;
        for (int j = 0; j < n; j++) {
            do {
                cout << "[" << j << "]: ";
                cin >> x[i][j];
            } while(x[i][j] < 10 || x[i][j] > 100);
        }
    }
}

void print_matrix(int n, int **x) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

void calculate_sum_rows(int n, int **x, int * sum_rows) {
    for (int i = 0; i < n; i++) {
        sum_rows[i] = 0;
        for (int j = 0; j < n; j++) {
            sum_rows[i] += x[i][j];
        }
    }
}

void calculate_sum_columns(int n, int **x, int * sum_columns) {
    for (int j = 0; j < n; j++) {
        sum_columns[j] = 0;
        for (int i = 0; i < n; i++) {
            sum_columns[j] += x[i][j];
        }
    }
}