#include <stdio.h>
#include <stdlib.h>

void setZero(char* array,char value,int length);
void FindRecord(char *filename, char *name, char record[]);
void Replace(char *name, char *newname, char record[]);
void SaveRecord(char *filename, char *name, char record[]);

int main(){
    
     // create space for name replacementName and record
    char* filename ="phonebook.csv";
    char* name = (char*)malloc(sizeof(char) * 1000);
    char* replacementName = (char*)malloc(sizeof(char) * 1000);
    char record [1000];
    
    //set the contents of name replacementName and record to 0
    setZero(name, 0, 1000);
    //memset(name, '\0', sizeof(char) * 1000);
    setZero(replacementName, 0, 1000);
    //memset(replacementName, '\0', sizeof(char) * 1000);
    setZero(record, 0, 1000);
    //memset(record, '\0', sizeof(char) * 1000);
    
    printf("Please Enter a name: ");
    scanf("%[^\n]%*c",name);
    printf("Name you Entered is: %s\n", name);
    FindRecord(filename,name,record);
    
    printf("Please Enter a replacement name: ");
    scanf("%[^\n]%*c",replacementName);
    printf("Replacement name you Entered is: %s\n", replacementName);
    Replace(name,replacementName,record);
    SaveRecord(filename, name, record);
    
    return 0;
}


void setZero(char* array,char value,int length){
    for (int i = 0; i<length; i++) {
        *array = value;
        array++;
    }
}

void FindRecord(char *filename, char *name, char record[]){
    int endTheLoop = 0;
    int index = 0;                          //to represent the pointer to shift
    int findname = 0;                       //if findname = 1 then i have found the record match the name
    
    FILE *fp = fopen(filename, "r");
    
    if (fp == NULL) {
        printf("File not found.\n");
        exit(0);
    }
    
    while(fgets(record, 1000, fp)){
        endTheLoop = 0;
        index = 0;
        while(endTheLoop == 0){                          //start searching for the name
            if(*(name + index) != *(record + index)){
                if(  (*(name + index) == '\0') && (*(record + index) == ',')){
                    findname = 1;                       //find the correct name
                    endTheLoop = 1;                     // end of the while loop with the required name
                }
                else{
                    endTheLoop = 1;                     //end of the while loop without the required name
                }
            }
            else{
                index++;
            }
        }
        if(findname == 1){
            break;
        }
    }
    
    if(findname != 1){
        printf("The person you are looking for does not exist! \n");
        exit(0);
    }
    fclose(fp);
}


void Replace(char *name, char *newname, char record[]){
    char* recordIterator = record;
    char* nameIterator = newname;
    
    char* temp = (char*)malloc(sizeof(char) * 1000);
    char* tempIterator = temp;
    for (; *recordIterator != ','; recordIterator++);
    
    //copy the rest part of record into temp
    while(*recordIterator != '\0'){
        *tempIterator = *recordIterator;
        tempIterator++;
        recordIterator++;
    }
    
    //set the point to the  beginning of array, and reset record
    recordIterator = record;
    tempIterator = temp;
    setZero(record, 0, 1000);
    
    //copy the newname into record
    while(*nameIterator != '\0') {
        *recordIterator = *nameIterator;
        recordIterator++;
        nameIterator++;
    }
    
    // copy the age and telephone number into record
    while(*tempIterator != '\0'){
        *recordIterator = *tempIterator;
        recordIterator++;
        tempIterator++;
    }
}



void SaveRecord(char *filename, char *name, char record[]){
    FILE *old = fopen(filename,"r");
    FILE *new = fopen("temp", "w+");

    char* temp = (char*)malloc(sizeof(char) * 1000);
    int notfound = 1;
    
    char* nameIterator;    //pointer for the name
    char* tempIterator;     //pointer for the temp
    
        //check whether it is the line we need
    while(fgets(temp,1000,old)){
        nameIterator = name;
        tempIterator = temp;
        
        //compare if it's the name entered to replace
        while(*nameIterator){
            if(*nameIterator == *tempIterator){
                notfound = 0;
                tempIterator++;
                nameIterator++;
            }
            else{
                notfound = 1;
                break;
            }
        }
    
        if(!notfound && *tempIterator == ','){ // if it is the one we are looking for, write it to the replacefile
            fprintf(new, "%s",record);
        }else{ //else copy the contents in the temp
            fprintf(new, "%s",temp);
        }
    }
    
    fclose(old);
    fclose(new);
    remove(filename);
    rename("temp", filename);
}


