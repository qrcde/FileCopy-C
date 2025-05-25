//A C program to copy contents of source file to a destination file using system calls. 
//Accepts source and destination file names from user input.
//Written and tested in Linux environment.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h> 

int main() {   
    char source[50]; 		//source file
    char destination[50]; 	//destination file
    int toread; 			//variable to store open file status
    int towrite; 			//variable to store create file status
    char buffer; 			//buffer variable to temporary store data while reading and writing
    
    //prompt user to enter source and destination file names
    printf("Enter a source file name: ");
    scanf("%s", &source);
    printf("Enter a destination file name: ");
    scanf("%s", &destination);
    
    toread = open(source, O_RDONLY);		//open the source file
        if (toread == -1) { 				//check if source file exists
            printf("Error opening file\n"); 
            exit(0);
         } else {
            towrite = open(destination, O_WRONLY | O_CREAT, 0644); //open or create a destination file
            if (towrite == -1) {
                printf("Error creating file");
                exit(0);
            } else {
		   while (read(toread, &buffer, 1)){ 	//read 1 byte at a time from source file
		   	write(towrite, &buffer, 1); 		//write 1 byte at a time to destination file
		   }
		   printf("Copy successful\n");
		   close(toread);
		   close(towrite);
            }
         }
    
    return 0;
 }//end main()