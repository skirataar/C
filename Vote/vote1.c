#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define MAX_VOTERS 10
#define MAX_NAME_LEN 50
#define MAX_ID_LEN 10

struct voter {
    char name[MAX_NAME_LEN];
    int age;
    char id[MAX_ID_LEN];
    int has_voted;
} voters[MAX_VOTERS];

void register_voters();
int check_eligibility(char* id);
void update_voter_record(char* id);
void record_vote(int option, int* vote_counts);
void write_results_to_file(int* vote_counts);

int main() {
    int i, option, vote_counts[5] = {0};
    
    register_voters();
    
    char username[20], password[20];
    int finished = 0,op;
    printf("Welcome to the Online Voting System!\n");
    printf("Please enter your username: ");
    scanf("%s", username);
    printf("Please enter your password: ");
    scanf("%s", password);
     if (strcmp(username, "u") == 0 && strcmp(password, "p") == 0) {
        printf("\nWelcome, %s!\n", username);
        finished=1;
     }
    
    while (finished) {
            printf("Press '1' to vote or '2' to exit: ");
            scanf("%d",&op);
            if(op==1){
                // Verify login credentials
                printf("Please enter your ID number: ");
                char id[MAX_ID_LEN];
                scanf("%s", id);
            
                // Check voter eligibility
                if (check_eligibility(id) == 1) {
                    printf("\nYou are eligible to vote. Please select your candidate:\n");
                    printf("1. Candidate A\n2. Candidate B\n3. Candidate C\n4. Candidate D\n5. Candidate E\n");
                    scanf("%d", &option);
                
                // Record vote
                    record_vote(option, vote_counts);
                
                // Update voter record
                    update_voter_record(id);
                
                    printf("Thank you for voting!\n");
                } 
                else {
                    printf("\nYou are not eligible to vote.\n");
                    exit(1);
                }
            }
            else{
                break;
            }
    }
    // Write results to file
    write_results_to_file(vote_counts);
    return 0;
}

void register_voters() {
    int i = 0;
    char name[MAX_NAME_LEN];
    int age;
    char id[MAX_ID_LEN];
    
    FILE *fp = fopen("voters.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    while (fscanf(fp, "%s %d %s", name, &age, id) == 3 && i < MAX_VOTERS) {
        strncpy(voters[i].name, name, MAX_NAME_LEN);
        voters[i].age = age;
        strncpy(voters[i].id, id, MAX_ID_LEN);
        voters[i].has_voted = 0;
        i++;
    }
    
    fclose(fp);
}

int check_eligibility(char* id) {
    int i;
    for (i=0; i<MAX_VOTERS; i++) {
        if (strcmp(voters[i].id, id) == 0) {
            if (voters[i].age >= 18 && voters[i].has_voted == 0) {
                return 1;
            } else {
                return 0;
            }
        }
    }
    return 0;
}

void update_voter_record(char* id) {
    int i;
    for (i=0; i<MAX_VOTERS; i++) {
        if (strcmp(voters[i].id, id) == 0) {
            voters[i].has_voted = 1;
            return;
        }
    }
}

void record_vote(int option, int* vote_counts) {
    switch(option) {
            case 1:
                    vote_counts[0]++;
                    break;
            case 2:
                    vote_counts[1]++;
                    break;
            case 3:
                    vote_counts[2]++;
                    break;
            case 4:
                    vote_counts[3]++;
                    break;
            case 5:
                    vote_counts[4]++;
                    break;
            default:
                    printf("Invalid option selected.\n");
    }
}

void write_results_to_file(int* vote_counts) {
    FILE *fp = fopen("results.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(fp, "Candidate A: %d\n", vote_counts[0]);
    fprintf(fp, "Candidate B: %d\n", vote_counts[1]);
    fprintf(fp, "Candidate C: %d\n", vote_counts[2]);
    fprintf(fp, "Candidate D: %d\n", vote_counts[3]);
    fprintf(fp, "Candidate E: %d\n", vote_counts[4]);
    fclose(fp);
}