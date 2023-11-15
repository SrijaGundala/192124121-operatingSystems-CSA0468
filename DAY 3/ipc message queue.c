//This program is written by G P Abinaya
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Fork failed!\n");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        struct msg_buffer message;
        message.msg_type = 1;
        printf("Enter message for process 1: ");
        fgets(message.msg_text, sizeof(message.msg_text), stdin);
        msgsnd(msgid, &message, sizeof(message), 0);
        printf("Message sent by process 2: %s", message.msg_text);
    } else {
        struct msg_buffer message;
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("Message received by process 1: %s", message.msg_text);
        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}
