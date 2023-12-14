"""
Write a python program to store marks scored in subject Fundamental of
Data Structure by N students in the class. Write functions to compute following:
a)	The average score of class 
b)	Highest score and lowest score of class 
c)	Count of students who were absent for the test
d)	Display mark with highest frequency

"""

def accept_marks(A):   
   n = int(input("Enter the total no. of student : "))
   for i in range(n) :
      while True :
         x = input("Enter the marks scored in FDS for student %d : "%(i+1))
         if(x == "AB"):
            x = -1   # indicates Absent students
            break
         x = int(x)
         if(x >= 0 and x <= 30) :
            break
         else :
            print("Plz enter valid marks out of 30")      
      A.append(x)
   print("Marks accepted & stored successfully");

def display_marks(A) :
   print("\nMarks Scored in FDS")
   for i in range(len(A)):
      if(A[i] == -1) :
         print("\tStudent %d : AB"%(i+1))
      else :
         print("\tStudent %d : %d"%(i+1,A[i]))
      
def search_set(A,X) :
    n = len(A)
    for i in range(n):
       if(A[i] == X) :
          return (1)
    return (0)

def find_average_score_of_class(A) :
   sum = 0
   for i in range(len(A)) :
      if(A[i] != -1) :
         sum = sum + A[i]
   avg = sum / len(A)
   display_marks(A)
   print("\nAverage score of class is %.2f\n\n"%avg)
   
def find_highest_and_lowest_score_of_class(A) :
   max = -1
   min = 31
   for i in range(1,len(A)) :
      if(max < A[i]) :
         max = A[i]
         max_ind = i
      if(min > A[i] and A[i] != -1) :
         min = A[i]
         min_ind = i
   display_marks(A)
   print("Highest Mark Score of class is %d scored by student %d"%(max,max_ind+1))
   print("Lowest Mark Score of class is %d scored by student %d"%(min,min_ind+1))
      
   
   
def find_count_of_absent_students(A) :
   count = 0
   for i in range(len(A)):
      if(A[i] == -1) :
         count += 1
   display_marks(A)
   print("\tAbsent Student Count = %d"%count)
      
def display_mark_with_highest_frequency(A) :
   freq = 0
   for i in range(len(A)) :
      count = 0
      if(A[i] != -1) :
         for j in range(len(A)):
            if(A[i] == A[j]) :
               count += 1
      if(freq < count) :
         Marks = A[i]
         freq = count
   display_marks(A)
   print("\nMarks with highest frequency is %d (%d)"%(Marks,freq))
   
def main():
   FDS_Marks = []
   while True :
      print ("\t\t1 : Accept FDS Marks")
      print ("\t\t2 : Average score of class")
      print ("\t\t3 : Highest score and lowest score of class")
      print ("\t\t4 : Count of students who were absent for the test")
      print ("\t\t5 : Display mark with highest frequency")
      print ("\t\t6 : Exit")
      ch = int(input("Enter your choice : "))
      if (ch == 6):
         print ("End of Program")
         quit()
      elif (ch == 1) :
         accept_marks(FDS_Marks)
         display_marks(FDS_Marks)
      elif (ch == 2) :
         find_average_score_of_class(FDS_Marks)
      elif (ch == 3) :
         find_highest_and_lowest_score_of_class(FDS_Marks)
      elif (ch == 4) :
         find_count_of_absent_students(FDS_Marks)
      elif (ch == 5) :
         display_mark_with_highest_frequency(FDS_Marks)
      else :
         print ("Wrong choice entered !! Try again")

main()












































"""def accept_set(A,Str): 
   n = int(input("Enter the total no. of student who play %s : "%Str))
   for i in range(n) :
      x = input("Enter the name of student %d who play %s : "%((i+1),Str))
      A.append(x)
   print("Set accepted successfully");

def display_set(A,Str): 
   n = len(A)
   if(n == 0) :
      print("\nGroup of Students who play %s =  { }"%Str)
   else :
      print("\nGroup of Students who play %s =  {"%Str,end=' ')
      for i in range(n-1) :
         print("%s,"%A[i],end=' ')
      print("%s }"%A[n-1]);
   
def search_set(A,X) :
    n = len(A)
    for i in range(n):
       if(A[i] == X) :
          return (1)
    return (0)


def find_intersection_set(A,B,C):
   for i in range(len(A)): 
      flag = search_set(B,A[i]);
      if(flag == 1) :
          C.append(A[i])

def find_difference_set(A,B,C):
    for i in range(len(A)): 
      flag = search_set(B,A[i]);
      if(flag == 0) :
          C.append(A[i])    


def find_union_set(A,B,C):
   for i in range(len(A)):
      C.append(A[i])
   for i in range(len(B)): 
      flag = search_set(A,B[i]);
      if(flag == 0) :
          C.append(B[i])    
       
def Main() :
   Group_A = []
   Group_B = []
   Group_C = []
   
   while True :
       print ("\t1 : Accept the Information")
       print ("\t2 : List of students who play both cricket and badminton")
       print ("\t3 : List of students who play either cricket or badminton but not both")
       print ("\t4 : Number of students who play neither cricket nor badminton")
       print ("\t5 : Number of students who play cricket and football but not badminton")
       print ("\t6 : Exit")
       ch = int(input("Enter your choice : "))
       Group_R = []       
       if (ch == 6):
           print ("End of Program")
           break
       elif (ch==1):
           accept_set(Group_A,"Cricket")
           accept_set(Group_B,"Badminton")
           accept_set(Group_C,"Football")
           display_set(Group_A,"Cricket")
           display_set(Group_B,"Badminton")
           display_set(Group_C,"Football")           
       elif (ch==2):
           display_set(Group_A,"Cricket")
           display_set(Group_B,"Badminton")
           find_intersection_set(Group_A,Group_B,Group_R)
           display_set(Group_R," both Cricket and Badminton")
       elif (ch==3):
           display_set(Group_A,"Cricket")
           display_set(Group_B,"Badminton")
           R1 = []
           find_union_set(Group_A,Group_B,R1)
           R2 = []
           find_intersection_set(Group_A,Group_B,R2)
           find_difference_set(R1,R2,Group_R)
           display_set(Group_R," either cricket or badminton but not both")
       elif (ch==4):
           display_set(Group_A,"Cricket")
           display_set(Group_B,"Badminton")
           display_set(Group_C,"Football")
           R1 = []
           find_union_set(Group_A,Group_B,R1)
           find_difference_set(Group_C,R1,Group_R)
           display_set(Group_R," neither cricket nor badminton")
           print("Number of students who play neither cricket nor badminton = %s"%len(Group_R))
       elif (ch==5):
           display_set(Group_A,"Cricket")
           display_set(Group_C,"Football")
           display_set(Group_B,"Badminton")
           R1 = []
           find_intersection_set(Group_A,Group_C,R1)           
           find_difference_set(R1,Group_B,Group_R)           
           display_set(Group_R,"cricket and football but not badminton")
           print("Number of students who play cricket and football but not badminton = %s"%len(Group_R))                 
       else :
           print ("Wrong choice entered !! Try again")


Main()
quit()

"""