#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;

struct Person{
    int code;
    char name[40];
    int age;
    double salary;
};

#define MAX 100

static int num_persons=0;
static char search_name[50];

void insert_client(char file_path[100], struct Person *lst_persons);
void read_file(char file_path[100], struct Person *lst_persons);
void sort_by_names(char* file_path, struct Person *lst_persons);
void update_client(char* file_path, char *search_name, struct Person *lst_persons);
void delete_client(char* file_path, char *search_name, struct Person *lst_clients);
int search_client(char* file_path, char *search_name, struct Person *lst_persons);
struct Person get_client(int pos, struct Person *lst_persons);
struct Person default_client();
void print_lst_clients(char* file_path, struct Person *lst_persons);
void print_client(struct Person c);

int main(){
    int pos, opt;
    struct Person p, *lst_persons;
    
    char file_path[100];

    lst_persons = new Person[MAX];

    strcpy(file_path, "data/person.txt");
    read_file(file_path, lst_persons);
    // input the data
    do{
        cout<<left;    
        cout << setw(20) << "\n --- MANAGMENT OF CLIENTS ---"<<endl;
        cout << "\nSelect an option from [1-8] according to the menu:" << endl;
        cout << "[1]. Insert client"<<endl;
        cout << "[2]. Read list of clients"<<endl;
        cout << "[3]. Search client"<<endl;
        cout << "[4]. Sort in alphabethic order"<<endl;
        cout << "[5]. Update client"<<endl;
        cout << "[6]. Delete client"<<endl;
        cout << "[7]. Find client with highest salary"<<endl;
        cout << "[8]. Exit"<<endl;
        cout << "------------------------------------------------"<<endl;
        cout << "Enter option: ";
        cin>> opt;
        switch(opt){
            case 1:     // insert
                insert_client(file_path, lst_persons);
                break;
            case 2:     // read 
                print_lst_clients(file_path, lst_persons);
                break;
            case 3:     // search                
                // get the position
                pos = search_client(file_path, search_name, lst_persons);
                
                // get the client
                p = get_client(pos, lst_persons);

                if(p.code != 0){
                    // print the client
                    cout<<"\nSearched client: "<<endl;
                    print_client(p);    
                }else{
                    cout<<"\nClient not found"<<endl;
                }
                
                break;
            case 4:     // sort data in alphabetic order
                cout<<"\nList of clients ordered alphabetically"<<endl;
                sort_by_names(file_path, lst_persons);
                print_lst_clients(file_path, lst_persons);
                break;
            case 5:     // update client                
                update_client(file_path, search_name, lst_persons);                
                break;
            case 6:     // delete client                
                delete_client(file_path, search_name, lst_persons);            
                break;
        }

    }while(opt != 8);
    // send the struct to write file

    // search_client(file_path, search_name, lst_persons)
    // read file

    // print struct person
    printf("\n***List of Persons***\n");

     

    cout << search_client(file_path, search_name, lst_persons);

    return 0;
}

void insert_client(char file_path[100], struct Person *lst_persons ){
    struct Person p;

    FILE *file;
    cout << num_persons;
    p.code = ++num_persons;
    cout<<"Name: ";
    cin>> p.name;

    do{
        cout<<"Age: ";
        cin>> p.age;
    }while(p.age <=0);

    do{
        cout<<"Salary: ";
        cin>>p.salary;
    }while(p.salary < 20000 || p.salary > 500000);

    

    file = fopen(file_path, "a");

    if(file){
        fprintf(file, "%i %s %d %.2f\n", p.code, p.name, p.age, p.salary);
        fclose(file);
    }else{
        printf("Error to open file\n");
    }

}
void sort_by_names(char* file_path, struct Person *lst_persons){
    FILE *file;
    
    struct Person p;

    for(int i=0; i<num_persons-1; i++){
        for(int j=i+1; j<num_persons; j++){
            if (strcmp(lst_persons[i].name, lst_persons[j].name) > 0){
                p = lst_persons[i];
                lst_persons[i] = lst_persons[j];
                lst_persons[j] = p;
            }
        }
    }
    file = fopen(file_path, "w");
    fprintf(file, "");
    fclose(file);
    file = fopen(file_path, "a");
    
    for(int i = 0; i < num_persons; i++){
        fprintf(file, "%i %s %d %.2f\n", (i + 1), 
        lst_persons[i].name, lst_persons[i].age, lst_persons[i].salary);
    }
    fclose(file);
    

}

void update_client(char* file_path, char *search_name, struct Person *lst_persons){
    FILE *file;
    
    int pos;    

    cout<< "\n*** Update Client ***"<<endl;

    // search client
    pos = search_client(file_path, search_name, lst_persons);

    if(pos != -1){
        // edit client        
        cout<<"Name: ";
        cin>>lst_persons[pos].name;

        do{
            cout<<"Age: ";
            cin>>lst_persons[pos].age;
        }while(lst_persons[pos].age <= 0);

        do{
            cout<<"Salary: ";
            cin>>lst_persons[pos].salary;
        }while(lst_persons[pos].salary < 20000 || lst_persons[pos].salary > 500000);
        
        file = fopen(file_path, "w");
        fprintf(file, "");
        fclose(file);
        file = fopen(file_path, "a");
        
        for(int i = 0; i < num_persons; i++){
            fprintf(file, "%i %s %d %.2f\n", lst_persons[i].code, 
            lst_persons[i].name, lst_persons[i].age, lst_persons[i].salary);
        }
        fclose(file);

        cout<<"\nClient updated!"<<endl;
    }else{
        cout<<"\nClient not found!"<<endl;
    }    
}

void delete_client(char* file_path, char *search_name, struct Person *lst_persons){
    FILE *file;

    int pos;

    cout<<"\n***Delete Client***"<<endl;

    // search client
    pos = search_client(file_path, search_name, lst_persons);

    if(pos != -1){
        for(int i=pos; i<num_persons; i++){
            lst_persons[i] = lst_persons[i+1];
        }
        num_persons--;

        file = fopen(file_path, "w");
        fprintf(file, "");
        fclose(file);
        file = fopen(file_path, "a");
        
        for(int i = 0; i < num_persons; i++){
            fprintf(file, "%i %s %d %.2f\n", (i + 1), 
            lst_persons[i].name, lst_persons[i].age, lst_persons[i].salary);
        }
        fclose(file);
        cout<<"\nClient deleted!"<<endl;
    }else{
        cout<<"\nClient not found"<<endl;
    }
}




void read_file(char file_path[100], struct Person *lst_persons){
    FILE *file;

    num_persons = 0;

    file = fopen(file_path, "r");

    if(file){
        while (fscanf(file, "%d %s %d %lf", &lst_persons[num_persons].code, 
                        lst_persons[num_persons].name, &lst_persons[num_persons].age, &lst_persons[num_persons].salary) == 4) {            
            num_persons++;
        }

        fclose(file);
    }else{
        printf("Error to open file\n");
    }
}

void print_lst_clients(char* file_path, struct Person *lst_persons){    
    
    read_file(file_path, lst_persons);

    cout<<left;
    cout<< setw(10) << "code" << setw(15) << "name" << setw(10) << "age"<< setw(10) << "salary" << endl;
    cout << "------------------------------------------------" << endl;

    if(num_persons != 0){
        for(int i = 0; i < num_persons; i++){
            print_client(lst_persons[i]);
        }
    }else{        
        printf("No persons\n");
    }
}

void print_client(struct Person c){
    cout<<setw(10)<<c.code<<
            setw(15)<<c.name<<
            setw(10)<<c.age<<
            setw(10)<<c.salary<<endl;
}

struct Person get_client(int pos, struct Person *lst_persons){
    if(pos != -1)
        return lst_persons[pos];
    else{        
        return default_client();
    }
}

struct Person default_client(){
    struct Person c;

    c.code = 0;
    c.name[0] = '\0';

    return c;
}

int search_client(char* file_path, char *search_name, struct Person *lst_persons){

    read_file(file_path, lst_persons);

    int pos;

    cout<< "\n*** Search Client ***"<<endl;
    cout<<"\nWrite the client searched: ";
    cin>>search_name;

    for(int i=0; i<num_persons; i++){
        if (strcmp(lst_persons[i].name, search_name) == 0){
            pos = i;
            break;
        }else{
            pos = -1;
        }
    }

    return pos;
}