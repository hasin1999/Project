
------------------------------------------------------------------------------------------------------
To run this file first open the command prompt and navigate to the directory of the files, then run the command
Make all 
to compile all the files in the src folder. then to run the algorith on the data file run this command:
.\bin.\main_ex1 .\data\records.csv .\data\sorted_records.csv 1 1
The first number refers to the field you want the files sotred based of (string, int, float).
The second number refers to the algorithm used to sort the file (merge sort, quick sort)
------------------------------------------------------------------------------------------------------
The execution times for Merge Sort and Quick Sort vary slightly based on the sorting key used. For Merge Sort, times are marginally longer for Field 1 compared to Fields 2 and 3, but the difference is minor. Both algorithms show similar times for Fields 2 and 3; however, a direct comparison for Field 1 is not possible due to Quick Sort's data absence, caused by its inefficiency with duplicate strings. The assignment notes that sorting operations extending beyond 10 minutes should be halted. The .csv file's numerous duplicate strings significantly slow Quick Sort and casuing it to timeout/stop. Overall, there is no significant performance difference between Merge Sort and Quick Sort. Any substantial difference would likely depend on the dataset size and distribution.