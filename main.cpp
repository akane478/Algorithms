//
//  main.cpp
//  Algorithms pt.2
//
//  Created by Allison Kane on 4/21/16.
//  Copyright © 2016 Allison Kane. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(int a[10000], int n);                   //initializing funcitons
void insertionSort (int a [10000], int n);
void swap (int *x, int *y);
int partition ( int a [], int low, int high);
void quickSort (int a [], int low, int high);
void shellsort(int a[], int n);

int main()
{
    int fu [10000]; //creates array for few_unique when it gets read in
    int n = 0;
    
    ifstream fin1;
    fin1.open("/Users/akane2/Documents/271 Programs/Algorithms pt.2/Algorithms pt.2/few_unique.txt");
    if (fin1.fail())
    {
        cerr << "Error opening file" << endl;
        exit (1);
    }
    while(!fin1.eof())      //reads til end of file and inserts integers into array
    {
        fin1 >> fu[n];
        n++;
    }
    
    cout << "we made it " <<endl;
    cout << "few unique file" << endl;
    bubbleSort(fu, n);
    insertionSort(fu, n);
    quickSort(fu, 0, 10000);
    shellsort(fu, n);
    

    
    int ns [10000];     //creates array for nearly_sorted when it gets read in

    int m = 0;
    
    ifstream fin2;
    fin2.open("/Users/akane2/Documents/271 Programs/Algorithms pt.2/Algorithms pt.2/nearly_sorted.txt);
    if (fin2.fail())
    {
        cerr << "Error opening file" << endl;
        exit (1);
    }
    while(!fin2.eof())      //reads til end of file and inserts integers into array
    {
        fin2 >> ns[m];
        m++;
    }
    for(int i=0; i < m ; i++)
    {
        cout << ns[i] << " ";
        
    }
    cout << "we made it " <<endl;
    cout << "nearly sorted file" << endl;
    bubbleSort(ns, n);
    insertionSort(ns, n);
    quickSort(ns, 0, 10000);
    shellsort(ns, n);
    
    int random [10000];         //creates array for random when it gets read in
    int x = 0;
    
    ifstream fin3;
    fin3.open("/Users/akane2/Documents/271 Programs/Algorithms pt.2/Algorithms pt.2/random.txt");
    if (fin3.fail())
    {
        cerr << "Error opening file" << endl;
        exit (1);
    }
    while(!fin3.eof())      //reads til end of file and inserts integers into array
    {
        fin3 >> random[x];
        x++;
    }
    for(int i=0; i < x ; i++)
    {
        cout << random[i] << " ";
        
    }
    cout << "we made it " <<endl;
    cout << "random file " << endl;
    
    
    bubbleSort(random, n);
    insertionSort(random, n);
    quickSort(random, 0, 10000);
    shellsort(random, n);
    
    int reversed [10000];           //creates array for reversed when it gets read in
    int y = 0;
    
    ifstream fin4;
    fin4.open("/Users/akane2/Documents/271 Programs/Algorithms pt.2/Algorithms pt.2/reversed.txt");
    if (fin4.fail())
    {
        cerr << "Error opening file" << endl;
        exit (1);
    }
    while(!fin4.eof()) //reads til end of file and inserts integers into array
    {
        fin4 >> reversed[y];
        y++;
    }
    for(int i=0; i < y ; i++)
    {
        cout << reversed[i] << " ";
        
    }
    cout << "we made it " <<endl;
    cout << "reversed file" << endl;
    bubbleSort(reversed, n);
    insertionSort(reversed, n);
    quickSort(reversed, 0, 10000);
    shellsort(reversed, n);

}




void bubbleSort(int a[10000], int n)            //funtion created to perform a bubble search algorithm
{
    int i, j, temp, swap, comp;
    for (i=1; i < n; i++)               //number of times it passes through
    {
        for (j = 0; j <n-i; j++)            //j will vary between 0 and n-1
        {
            swap++;
            if (a[j] > a [j+1])             //compares the successive numbers
            {
                temp = a[j];                    //swaps j with j+1
                a[j] = a[j+1];
                a[j+1] = temp;
                comp++;
            }
        }
    }
    cout << "Number of swaps: " << swap << endl;
    cout << "number of comparisons; " << comp << endl;
}

void insertionSort (int a [10000], int n)
{
    int i, j, element, swap, comp;
    for (i=1; i< n; i++)
    {
        element = a[i]; //insert the ith element in array
        j=i;
        swap++;
        while ((j>0) && (a[j-1] > element)) //compares if a[j-1] > element
        {
            a[j] = a[j-1];          //will shift the elements
            j= j-1;
            comp++;

        }
        a[j] = element; // elemnet placed at jth position
    }
    cout << "Number of swaps: " << swap << endl;
    cout << "Number of comp: " << comp << endl;

}
#define max 10000

void swap (int *x, int *y) // swaps the elements using a temp int
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void quickSort (int a [], int low, int high) //uses the partition to quicksort the array
{
    int k, j=0;
    if (low < high)
    {
        k = partition (a, low, high);
        quickSort(a, low, j-1);
        quickSort(a, j+1, high);
    }
}
int partition ( int a [], int low, int high) //partitions the array
{
    int pivot, i, j;
    pivot = a[low];
    j = high +1; i = low;
    do{
        i++;
        
        while (a[i] < pivot && low <= high )
            do
            {
                j++;
            }
        while (pivot < a[j]);
        if (i < j)
            swap (a[i], a[j]);
    }
    while (i <j);
    a[low] = a[j];
    a[j]= pivot;
    return j;
}
void shellsort(int a[], int n) //shellsorts the array as a function that gets called

{
    
    int gap, i, j, temp, comp, swap;
    
    
    
    for (gap = n/2; gap > 0; gap /= 2)
        
        for (i = gap; i < n; i++)
            comp++;
            
            for (j=i-gap; j>=0 && a[j]>a[j+gap]; j-=gap)
            {
                
                temp = a[j];
                
                a[j] = a[j+gap];
                
                a[j+gap] = temp;
                swap++;
                
            }
    cout << "number of swap: " << swap << endl;

    cout << "number of comp: " << comp << endl;
}

