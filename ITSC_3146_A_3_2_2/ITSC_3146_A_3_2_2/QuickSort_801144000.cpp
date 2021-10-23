//
//  QuickSort_Skeleton.cpp
//
//  Created by Bahamon, Julio on 6/25/19.
//  UNC Charlotte
//  Copyright © 2019 Bahamon, Julio. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//  Declaring a new struct to store patient data
struct patient {
    int age;
    char name[20];
    float balance;
};


//Compare function to sort by age for qsort
int ageCompare(const void * a, const void * b) {
    if ((*(patient*)a).age < (*(patient*)b).age) {
        return -1;
    } else if ((*(patient*)a).age == (*(patient*)b).age) {
        return 0;
    }   else {
        return 1;
    }
}


//Compare function to sort by balance for qsort
int balanceCompare(const void * a, const void * b) {
    if ((*(patient*)a).balance < (*(patient*)b).balance) {
        return -1;
    } else if ((*(patient*)a).balance == (*(patient*)b).balance) {
        return 0;
    }   else {
        return 1;
    }
}

//Compare function to sort by name for qsort
int nameCompare (const void * a, const void * b) {
    if (strncmp((*(patient*)a).name, (*(patient*)b).name, 3) < 0) {
        return -1;
    }   else if (strncmp((*(patient*)a).name, (*(patient*)b).name, 3) == 0) {
        return 0;
    }   else {
        return 1;
    }
}

//  The main program
int main()
{
    int total_patients = 6;
    
    //  Storing some test data
    struct patient patient_list[6] = {
        {25, "Juan Valdez   ", 1250},
        {15, "James Morris  ", 2100},
        {32, "Tyra Banks    ", 750},
        {62, "Maria O'Donell", 375},
        {53, "Pablo Picasso ", 615},
        {19, "Ansh Sawant   ", 0}
    };
    
    //Prints unsorted patient list
    cout << "Patient List: " << endl;
    cout << "Name:                Age:       Balance Due:" << endl;
    for(int i=0; i<total_patients; i++)
        printf("%-20s %-10d %f\n", patient_list[i].name, patient_list[i].age, patient_list[i].balance);
    cout << endl;
    
    
    cout << "Sorting..." << endl;
    
    //Uses qsort to sort patients by age
    qsort (patient_list, 6, sizeof(patient), ageCompare);
    
    cout << "Patient List - Sorted by Age: " << endl;
    cout << "Name:                Age:       Balance Due:" << endl;

    //Displays sorted patient list
    for(int i=0; i<total_patients; i++)
        printf("%-20s %-10d %f\n", patient_list[i].name, patient_list[i].age, patient_list[i].balance);
    
    cout << endl;
    
    
    cout << "Sorting..." << endl;
    
    
    //Uses qsort to sort patients by balance
    qsort (patient_list, 6, sizeof(patient), balanceCompare);
    
    cout << "Patient List - Sorted by Balance Due: " << endl;
    cout << "Name:                Age:       Balance Due:" << endl;

    //Displays sorted patient list
    for(int i=0; i<total_patients; i++)
        printf("%-20s %-10d %f\n", patient_list[i].name, patient_list[i].age, patient_list[i].balance);
    
    cout << endl;
    
    
    cout << "Sorting..." << endl;
    

    //Uses qsort to sort patients by name
    qsort (patient_list, 6, sizeof(patient), nameCompare);
    
    cout << "Patient List - Sorted by Name: " << endl;
    cout << "Name:                Age:       Balance Due:" << endl;
    
    //Displays sorted patient list
    for(int i=0; i<total_patients; i++)
        printf("%-20s %-10d %f\n", patient_list[i].name, patient_list[i].age, patient_list[i].balance);
    
    cout << endl;
    
    return 0;
}
