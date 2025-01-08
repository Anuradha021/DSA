#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define SERVER_ADDRESS "127.0.0.1"
#define MAX_BUFFER 1024

int client_socket;
struct sockaddr_in server_info;

void initialize_socket();
void establish_connection();
void send_to_server();
void receive_from_server();
void close_connection();

int main() {
    initialize_socket();
    establish_connection();
    send_to_server();
    receive_from_server();
    close_connection();
    return 0;
}

void initialize_socket() {
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error in socket creation");
        exit(EXIT_FAILURE);
    }
}

void establish_connection() {
    server_info.sin_family = AF_INET;
    server_info.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_info.sin_addr);

    if (connect(client_socket, (struct sockaddr*)&server_info, sizeof(server_info)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }
    printf("Connected to server at %s:%d\n", SERVER_ADDRESS, SERVER_PORT);
}

void send_to_server() {
    char input[MAX_BUFFER];
    printf("your message for the server: ");
    fgets(input, MAX_BUFFER, stdin);
    input[strcspn(input, "\n")] = '\0';  

    send(client_socket, input, strlen(input), 0);
    printf("Message sent: %s\n", input);
}

void receive_from_server() {
    char reply[MAX_BUFFER] = {0};
    read(client_socket, reply, MAX_BUFFER);
    printf("Response  from server: %s\n", reply);
}

void close_connection() {
    close(client_socket);
    printf("Connection closed.\n");
}
