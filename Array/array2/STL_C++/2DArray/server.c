#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_NUMBER 4242
#define MAX_BUFFER_SIZE 1024

int server_socket, connection_socket;
struct sockaddr_in server_addr, client_addr;
socklen_t client_addr_len = sizeof(client_addr);

void initialize_socket();
void bind_server();
void start_listening();
void accept_client();
void process_client();
void cleanup();

int main() {
    initialize_socket();
    bind_server();
    start_listening();
    accept_client();
    process_client();
    cleanup();
    return 0;
}

void initialize_socket() {
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
}

void bind_server() {
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT_NUMBER);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }
}

void start_listening() {
    if (listen(server_socket, 1) < 0) {
        perror("Error in listen");
        exit(EXIT_FAILURE);
    }
    printf("Server is waiting on port %d\n", PORT_NUMBER);
}

void accept_client() {
    if ((connection_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len)) < 0) {
        perror("Failed to accept client");
        exit(EXIT_FAILURE);
    }
    printf("Connected to client\n");
}

void process_client() {
    char message_buffer[MAX_BUFFER_SIZE] = {0};

    
    read(connection_socket, message_buffer, MAX_BUFFER_SIZE);
    printf("Received from client: %s\n", message_buffer);

    
    send(connection_socket, message_buffer, strlen(message_buffer), 0);
    printf("Message echoed back to client.\n");
}

void cleanup() {
    close(connection_socket);
    close(server_socket);
    printf("Server and client connections closed.\n");
}
