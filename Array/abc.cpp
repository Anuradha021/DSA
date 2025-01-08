#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
#include<fcntl.h>
#include<string.h>

#define OPEN_SUCCESS "File Open Successful\n"
#define OPEN_ERROR "File Open Failed\n"

void create_file();
void open_file();
size_t read_file(FILE *fp,char *buffer,int length);
void process_students();
void move_to_next_student(FILE *fp, int current);

typedef struct student_type
{
    int id;
    char name[32];
    char college[32];
    char passing_year[16];
} student_t;

int compare_student(student_t *student1, student_t *student2);

// Corrected function to open file in read mode
FILE* open_file_in_read_mode(char *file_name)
{
    FILE *fp = fopen(file_name, "r");
    if (fp != NULL)
    {
        printf(OPEN_SUCCESS);
    } 
    else 
    {
        printf(OPEN_ERROR);
    }
    return fp;
}

// Corrected function to open file in read-write mode
FILE* open_file_in_read_write_mode(char *file_name)
{
    FILE *fp = fopen(file_name, "w+");
    if (fp != NULL)
    {
        printf(OPEN_SUCCESS);
    } 
    else 
    {
        printf(OPEN_ERROR);
    }
    return fp;
}

// Function to read student record from the file
student_t* read_student_from_file(FILE *fp)
{
    student_t *student = malloc(sizeof(student_t));
    if (fscanf(fp, "%d %s %s %s", &student->id, student->name, student->college, student->passing_year) != 4) 
    {
        free(student);
        return NULL;
    }
    return student;
}

// Function to read from a specific location in the file
size_t read_from_location(FILE *fp, char *buffer, int position, int length)
{
    fseek(fp, position, SEEK_SET);
    return fread(buffer, sizeof(char), length, fp);
}

// Function to write student record to the file
void write_student_to_file(FILE *fp, student_t *student)
{
    fprintf(fp, "%d %s %s %s\n", student->id, student->name, student->college, student->passing_year);
}

// Function to write data to a file
size_t write_file(FILE *fp, char *data)
{
    return fwrite(data, sizeof(char), strlen(data), fp);
}

// Function to read data from the file
size_t read_file(FILE *fp, char *buffer, int length)
{
    return fread(buffer, sizeof(char), length, fp);
}

//=======================================================
// DO NOT MODIFY CODE BELOW

int main(int argc, char *argv[])
{
    char buffer[1024];
    int input_data_length  = 0;
    int create;
    scanf("%s", buffer);
    scanf("%d", &create);
    input_data_length = strlen(buffer);

    if (create > 0)
    {
        create_file();
    }

    FILE *fp = open_file_in_read_mode("test.txt");
    if (create <= 0)
    {
        return 0;
    }

    if (fp == NULL)
    {
        printf("Invalid file descriptor returned by open_file_in_read_mode\n");
    }

    // Test the write, if the write
    int size = (int)write_file(fp, buffer);
    if (size > 0)
    {
        printf("Invalid open mode\n");
    }

    fclose(fp);

    fp = open_file_in_read_write_mode("test.txt");

    // Test the write
    size_t write_size = write_file(fp, buffer);
    if (write_size < input_data_length || write_size > (input_data_length + 1))
    {
        printf("Write Failed\n");
    }

    fclose(fp);
    fp = open_file_in_read_mode("test.txt");

    char buffer_read[1024];
    size = (int)read_file(fp, buffer_read, 1024);
    if (size != write_size)
    {
        printf("Invalid Size of the data returned\n");
    }

    printf("Data Written: %s\n", buffer);
    printf("Data Read: %s\n", buffer_read);
    if (strcmp(buffer, buffer_read))
    {
        printf("Data Written did not match with Data Read\n");
    }
    fclose(fp);
    process_students();
}

void process_students()
{
    int student_count;
    student_t *students[100];
    FILE *fp = open_file_in_read_write_mode("test.txt");

    scanf("%d", &student_count);
    for (int i = 0; i < student_count; i++)
    {
        student_t *student = read_student_from_file(stdin);
        printf("id: %d, name: %s, college: %s, passing_year: %s\n",
               student->id, student->name, student->college, student->passing_year);
        write_student_to_file(fp, student);
        students[i] = student;
    }

    fseek(fp, 0, SEEK_SET);
    for (int i = 0; i < student_count; i++)
    {
        student_t *student = read_student_from_file(fp);
        if (!compare_student(student, students[i]))
        {
            printf("Read/Write Student did not work properly\n");
        }
    }

    // Dump file data
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char buffer_read[2048];
    read_file(fp, buffer_read, 2048);
    buffer_read[file_size] = '\0';
    printf("File Data: %s\n", buffer_read);

    fseek(fp, 0, SEEK_END);

    int position = file_size / 2;
    char buffer[1024];
    size_t size = read_from_location(fp, buffer, position, position);
    buffer[size] = '\0';
    printf("Data Read at location: %d, is %s and size is: %zu\n", position, buffer, size);

    fclose(fp);
}

int compare_student(student_t *student1, student_t *student2)
{
    if (student1->id != student2->id)
    {
        return 1;
    }
    if (strcmp(student1->name, student2->name))
    {
        return 1;
    }
    if (strcmp(student1->college, student2->college))
    {
        return 1;
    }
    if (strcmp(student1->passing_year, student2->passing_year))
    {
        return 1;
    }
    return 0;
}

void create_file()
{
    pid_t cid = fork();
    if (cid == 0)
    {
        char *args[] = {"touch", "test.txt", NULL};
        execvp(args[0], args);
    }
    else
    {
        wait(NULL);
    }
}