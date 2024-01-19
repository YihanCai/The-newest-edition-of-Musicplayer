#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

void play_music(const char filename[]);
void yuyin(char con[]);
void input_str(char* content);


int main() {
    printf("����������Ҫ�ϳ�Ϊ���Ե�����:\n");
    char content[1000];
    input_str(content);
    yuyin(content);
    while (1);

    return 0;
}

void play_music(const char filename[]) {
    char openCommand[256], playCommand[256];

    // Close any currently playing music
    sprintf(openCommand, "close music");
    mciSendString(openCommand, 0, 0, 0);

    // Open the specified music file with an alias
    sprintf(openCommand, "open \"%s\" alias music", filename);
    mciSendString(openCommand, 0, 0, 0);

    // Play the music
    sprintf(playCommand, "play music");
    mciSendString(playCommand, 0, 0, 0);
}

void yuyin(char con[]) {
    const char* synthesisCommand = "speech_synthesis.exe";
    const char* outputFilename = "output.wav";

    char command[2000];
    sprintf(command, "%s --txt \"%s\" --filename \"%s\"", synthesisCommand, con, outputFilename);

    // Execute the speech synthesis command
    if (system(command) != 0) {
        printf("�ϳ�����ʧ�ܡ�\n");
        exit(1);
    }
    play_music(outputFilename);
    printf("�����ϳ���ɣ�����Ϊ������!\n");
}

void input_str(char* content) {
    
    if (scanf("%999s", content) != 1) {
        printf("������Ч��\n");
        exit(1);
    }
}