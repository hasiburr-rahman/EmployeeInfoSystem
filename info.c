#include<stdio.h>
#include<string.h>

typedef struct info{
    int id;
    char name[100];
    char blood[20];
    char area[50];
}x;

int update(int n, x people[], char ch[]);

int main(){
    int i, n, idx;
    char ch[30];
    x people[100];

    FILE *file = fopen("information.txt", "r");

    fscanf(file, "%d", &n);
    fgetc(file);

    for(i=0; i<n; i++){
        fscanf(file, "%d", &people[i].id);
        fgetc(file);
        fgets(people[i].name, 100, file);
        people[i].name[strcspn(people[i].name, "\n")] = '\0';
        fgets(people[i].blood, 100, file);
        people[i].blood[strcspn(people[i].blood, "\n")] = '\0';
        fgets(people[i].area, 100, file);
        people[i].area[strcspn(people[i].area, "\n")] = '\0';
        }
        
        printf("Enter the name you want to find out the information - ");
        fgets(ch, 30, stdin);
        ch[strcspn(ch, "\n")] = '\0';
        
        idx = update(n, people, ch);
        
        printf("<<<------ Employees' Information ------>>>\n");
        if(idx != -1){
            printf("ID - %d\nNAME - %s\nBlood Group - %s\nAddress - %s", people[idx].id, people[idx].name, people[idx].blood, people[idx].area);
        }
        else{
            printf("NOT FOUND!!");
        }

}

int update(int n, x people[], char ch[]){
    int i;
    for(i=0; i<n; i++){
        if(strcmp(people[i].name, ch) == 0){
            return i;
        }
    }

    return -1;
}