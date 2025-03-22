#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;



/*
void input_num_elmnts(int* n);
void input_vector(int n, int* x);
int* allocate_memory(int n);
double calculate_mean(int n, int* x);
void print_vector(int n, int* x);


int main() {
	int n, * a, * b, * c;
	double e_dist;

	input_num_elmnts(&n);

	a = allocate_memory(n);
	b = allocate_memory(n);

	cout << "Enter elements of vector: " << endl;
	cout << "A: " << endl;
	input_vector(n, a);
	cout << "B: " << endl;
	input_vector(n, b);

	cout << "Vector A: " <<  endl;
	print_vector(n, a);
	cout << "Vector B: " << endl;
	print_vector(n, b);
}

void input_num_elmnts (int *n) {
	do {
		cout << "\nEnter number of elements: ";
		cin >> *n;
	} while (*n < 0);
}

int* allocate_memory(int n) {
	return (int*) malloc(n * sizeof(int));
}

void input_vector(int n, int* x) {
	for (int i = 0; i < n; i++) {
		cout << "X[" << i << "]";
		cin >> x[i];
	}
}

void print_vector(int n, int* x) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
};

double calculate_mean(int n, int* x) {
	double sum = 0.0;
	for (int i = 0; i < n; i++) {
		sum += x[i];
	}

	return sum / n;
} */




void input_num_elmnts(int* n);
void input_vector(int n, int* x);
int* allocate_memory(int n);
void print_vector(int n, int* x);
bool is_starx(int n, int* x);
int generate_number(int n, int*a);
int search_highest_digits(int num);
void vector_of_max_digits(int n, int* x, int* y);
void vec_count_digits(int n, int *x, int *d);
void count_digits(int num, int *d);



int main() {
	int n, * a, * b, * d, c;

	input_num_elmnts(&n);

	a = allocate_memory(n);
	b = allocate_memory(n);
	d = allocate_memory(10);

	cout << "\nEnter elements of vector (ONLY from 1000 to 10000): " << endl;
	cout << "A: " << endl;
	input_vector(n, a);

	cout << "\nVector A: " << endl;
	print_vector(n, a);

	if (is_starx(n, a)) {
		cout << "Vector is starx!!!!" << endl;
	}
	else {
		cout << "Vector is not starx :((((" << endl;
	}
	cout << endl;

	vector_of_max_digits(n, a, b);

	cout << "Max digits: " << endl;

	print_vector(n, b);
	cout << endl;
	cout << "Num of max nums: ";
	cout << generate_number(n, b) << endl;
	cout << endl;

	vec_count_digits(n, a, d);
	cout << "Number of all digits in vector A:" << endl;
	print_vector(10, d);

}








void input_num_elmnts(int* n) {
	do {
		cout << "\nEnter number of elements (from 2 and even): ";
		cin >> *n;
	} while (*n < 2 || *n % 2 != 0);
}

int* allocate_memory(int n) {
	return (int*)malloc(n * sizeof(int));
}

void input_vector(int n, int* x) {
	for (int i = 0; i < n; i++) {
		do {
			cout << "X[" << i << "]";
			cin >> x[i];
		} while (x[i] < 1000 || x[i] > 10000);
	}
}

void print_vector(int n, int* x) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void vector_of_max_digits(int n, int* x, int * y) {
	for (int i = 0; i < n; i++) {
		y[i] = search_highest_digits(x[i]);
	}
	cout << endl;
}

bool is_starx(int n, int* x) {
	int* even, * odd, cnt = 0;
	bool flag = true;
	even = x;
	odd = x;

	while (cnt < n / 2 && flag) {
		if (*(even + (2 * cnt)) < *(even + (2 * cnt) + 1)) {
			flag = false;
			break;
		}
		cnt ++;
	}
	return flag;
}

int generate_number(int n, int*a){
	long long num = 0, order = 1;

	for(int i = 0; i < n; i++) {
		num += a[i] * order;
		order *= 10;
	}

	return num;
}

int search_highest_digits(int num) {
	int aux, dig, max_digit = -1;
	aux = num;

	while (aux > 0) {
		dig = aux % 10;
		max_digit = max(dig, max_digit);
		aux /= 10;
	}

	return max_digit;
}

void vec_count_digits(int n, int *x, int *d) {
	for (int i = 0; i < 10; i++) {
		d[i] = 0;
	}

	for (int i = 0; i<n; i++) {
		count_digits(x[i], d);
	}
}


void count_digits(int num, int *d) {
	int aux, dig;
	aux = num;

	while (aux > 0) {
		dig = aux % 10;
		d[dig]++;
		aux = aux / 10;
	}
}