#include <stdio.h>
#include <string.h>
typedef struct
{
    int id;
    char title[100];
    char director[100];
    int year;
} Movie;

Movie library[100];
int count=0;

void addMovie();
void displayMovies();
void searchMovie();
void deleteMovie();

int main() {
    int choice;

    do {
        printf("\n--- Movie Library---\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search Movie\n");
        printf("4. Delete Movie\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                displayMovies();
                break;
            case 3:
                searchMovie();
                break;
            case 4:
                deleteMovie();
                break;
            case 5:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!=5);

    return 0;
}

void addMovie() {
    if (count>=100) {
        printf("Library is full.\n");
        return;
    }

    Movie newMovie;
    newMovie.id=count + 1;
    char title[100];
    printf("Enter movie title: ");
    scanf(" %[^\n]",title);
    strcpy(newMovie.title,title);
    char dir[100];
    printf("Enter director name: ");
    scanf(" %[^\n]",dir);
    strcpy(newMovie.director,dir);
    printf("Enter release year: ");
    scanf("%d",&newMovie.year);

    library[count++]=newMovie;
    printf("Movie added!\n");
}

void displayMovies() {
    if (count==0) 
    {
        printf("No movies in the library.\n");
        return;
    }
    
    printf("\n--- Movie Library ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n",library[i].id);
        printf("Title: %s\n",library[i].title);
        printf("Director: %s\n",library[i].director);
        printf("Year: %d\n",library[i].year);
        printf("\n");
    }
}

void searchMovie() {
    char searchTitle[100];
    printf("Enter movie title to search: ");
    getchar(); 
    fgets(searchTitle,100,stdin);
    searchTitle[strcspn(searchTitle,"\n")] = 0; 

    for (int i=0;i<count;i++) {
        if (strcasecmp(library[i].title,searchTitle)==0) {
            printf("Movie found!\n");
            printf("ID: %d\n", library[i].id);
            printf("Title: %s\n", library[i].title);
            printf("Director: %s\n", library[i].director);
            printf("Year: %d\n", library[i].year);
            return;
        }
    }

    printf("Movie not found.\n");
}

void deleteMovie() {
    int deleteId;
    printf("Enter movie ID to delete: ");
    scanf("%d", &deleteId);

    int found = 0;
    for (int i = 0;i<count;i++) {
        if (library[i].id==deleteId) {
            found = 1;
            for (int j=i;j<count-1;j++) {
                library[j]=library[j+1];
            }
            count--;
            printf("Movie deleted!\n");
            break;
        }
    }

    if (!found) {
        printf("Movie with ID %d not found.\n", deleteId);
    }
}
