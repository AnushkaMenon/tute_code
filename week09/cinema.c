
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cinema.h"
struct movie {
    char title[MAX_STR_LENGTH];
    int length;
    double rating;

    struct movie *next;
};

struct genre {
    char name[MAX_STR_LENGTH];

    struct movie *movies;
    struct genre *next;
};

struct cinema {
    struct genre *genres;
};

struct cinema *create_cinema() {
    struct cinema *new = malloc(sizeof(struct cinema));
    new->genres = NULL;

    return new;
}

void add_genre(struct cinema *cinema, char *genre_name) {
    struct genre *new = malloc(sizeof(struct genre));
    strcpy(new->name, genre_name);
    new->movies = NULL;
    new->next = NULL;

    new->next = cinema->genres;
    cinema->genres = new;
}

int add_movie(
    struct cinema *cinema,
    char *genre_name,
    char *movie_name,
    int length,
    double rating
) {
    // loop through genres to find the genre struct we want
    //  to add the movie to
    int found = 0;
    
    struct genre *curr_genre = cinema->genres;
    while (curr_genre != NULL && found == 0) {
        // exit loop once we've found a matching genre
        if (strcmp(curr_genre->name, genre_name) == 0) {
            found = 1;
        } else {
            curr_genre = curr_genre->next;
        }
    }
    
    // at this point, if found == 1, curr_genre will be the struct
    //  genre for the genre we were looking format
    // OR found == 0, in which case the genre we were looking format
    //  wasn't in the linked list
    if (found == 0) {
        return NOT_FOUND;
    }
    
    // create struct movie
    struct movie *new_movie = malloc(sizeof(struct movie));
    strcpy(new_movie->title, movie_name);
    new_movie->length = length;
    new_movie->rating = rating;
    new_movie->next = NULL;
    
    // add the new movie to head of its genre's movie linked list
    new_movie->next = curr_genre->movies;
    curr_genre->movies = new_movie;
    
    return SUCCESS;
}

void print_genre(struct cinema *cinema, char *genre_name) {
    // loop through genres to find the required genre
    int found = 0;
    
    struct genre *curr_genre = cinema->genres;
    while (curr_genre != NULL && found == 0) {
        if (strcmp(curr_genre->name, genre_name) == 0) {
            found = 1;
        } else {
            curr_genre = curr_genre->next;
        }
    }
    
    // if the genre doesn't exist in the linked list, just return
    if (found == 0) {
        return;
    }
    
    // if the genre does exist, loop through all of its movies and
    //  print out their information
    struct movie *curr_movie = curr_genre->movies;
    while (curr_movie != NULL) {
        printf("%s, %.2lf/10 (%d minutes)\n", curr_movie->title, curr_movie->rating, curr_movie->length);
        curr_movie = curr_movie->next;
    }
    
}
