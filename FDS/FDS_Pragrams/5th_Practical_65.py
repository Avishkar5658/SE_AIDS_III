"""
       Group B - Assignment 16
Write a python program to store first year percentage of students in array.
Write function for sorting array of floating point numbers in ascending order
using quick sort and display top five scores..

"""

def accept_array(A): 
   n = int(input("Enter the total no. of student : "))
   for i in range(n):
      x = float(input("Enter the  first year percentage of student %d : "%(i+1)))
      A.append(x)
   print("Array accepted successfully\n\n");

def display_array(A): 
   n = len(A)
   if(n == 0) :
      print("\nNo records in the database")
   else :
      print("Array of FE Marks : ",end=' ')
      for i in range(n) :
         print("%.2f  "%A[i],end=' ')
      print("\n");

def partition(A,s,l) :
   b=s+1
   e=l
   while(e>=b) :
      while(b<=l and A[s] >= A[b]) :
         b = b + 1
      while(A[s] <A[e]) :
         e = e - 1
      if(e>b) :
         temp = A[e]
         A[e] = A[b]
         A[b] = temp
   temp = A[s]
   A[s] = A[e]
   A[e] = temp
   return e

def Quicksort(A,s,l) :
   if(s<l) :
      mid = partition(A,s,l)
      Quicksort(A,s,mid-1)
      Quicksort(A,mid+1,l)


     
def Main() :   
   A = []
   while True :
      print ("\t1 : Accept & Display the FE Marks")      
      print ("\t2 : Quick sort ascending order and display top five scores")
      print ("\t3 : Exit")
      ch = int(input("Enter your choice : "))
      if (ch == 3):
         print ("End of Program")
         quit()
      elif (ch==1):
         A = []
         accept_array(A)
         display_array(A)
      elif (ch==2):
         print("Marks before sorting")
         display_array(A)
         n =len(A)
         Quicksort(A,0,n-1)
         print("Marks after sorting")
         display_array(A)         
         if(n >= 5) :
            print("Top Five Scores : ")
            for i in range(n-1,n-6,-1) :
               print("\t%.2f"%A[i])
         else :
            print("Top Scorers : ")
            for i in range(n-1,-1,-1) :
               print("\t%.2f"%A[i])                               
      else :
           print ("Wrong choice entered !! Try again")


Main()



















































"""
def bubbleSort(arr): 
        n = len(arr)
    
        # Traverse through all array elements \n",
        for i in range(n-1): 
         
            for j in range(0, n-i-1): 
    
                # traverse the array from 0 to n-i-1 \n",
                # Swap if the element found is greater \n",
                # than the next element \n",
                if arr[j] > arr[j+1]: 
                	arr[j], arr[j+1] = arr[j+1], arr[j] 
arr=[]
Num=int(input("Enter the number of students "))
for i in range (Num):
        per=float(input("Enter the percentage marks "))
        arr.append(per)
    
bubbleSort(arr)
    
print ("Sorted array is:") 
for i in range(len(arr)): 
	print ("%f" %arr[i])
  
  
a,b=10,20
print(a,b)
a,b=b,a
print(a,b)
   
def selectionSort(arr1):
    
        for i in range(len(arr1)): 
            min_idx = i 
            for j in range(i+1, len(arr1)): 
                if arr1[min_idx] > arr1[j]: 
                    min_idx = j
    
        # Swap the found minimum element with  \n",
        # the first element         \n",
            arr1[i], arr1[min_idx] = arr1[min_idx], arr1[i] 
    
arr1=[]
Num=int(input("Enter the number of students "))
for i in range (Num):
	per=float(input("Enter the percentage marks "))
	arr1.append(per)
    
selectionSort(arr1)
# Driver code to test above \n",
print ("Sorted array") 
for i in range(len(arr1)): 
        print("%f" %arr1[i])
  
a,b=10,20
print(a,b)
a,b=b,a
print(a,b)
"""