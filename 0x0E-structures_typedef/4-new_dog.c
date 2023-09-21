#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for the dog object
typedef struct {
    char *name;
    float age;
    char *owner;
} dog_t;

// Function to create a new dog object
dog_t* new_dog(char *name, float age, char *owner) {
    // Allocate memory for the dog object
    dog_t *newDog = (dog_t *)malloc(sizeof(dog_t));
    
    // Check if memory allocation was successful
    if (newDog == NULL) {
        return NULL; // Return NULL if allocation fails
    }
    
    // Allocate memory and copy the name string
    newDog->name = strdup(name);
    if (newDog->name == NULL) {
        free(newDog); // Free previously allocated memory
        return NULL;
    }
    
    // Set the age and allocate memory for the owner string
    newDog->age = age;
    newDog->owner = strdup(owner);
    
    // Check if memory allocation was successful
    if (newDog->owner == NULL) {
        free(newDog->name); // Free previously allocated memory
        free(newDog);
        return NULL;
    }
    
    return newDog; // Return the newly created dog object
}

int main() {
    // Example usage
    dog_t *myDog = new_dog("Buddy", 3.5, "John Doe");
    
    if (myDog != NULL) {
        printf("Created a dog named %s, age %.1f, owned by %s\n", myDog->name, myDog->age, myDog->owner);
    } else {
        printf("Failed to create a dog object.\n");
    }
    
    // Don't forget to free the memory when done using the dog object
    if (myDog != NULL) {
        free(myDog->name);
        free(myDog->owner);
        free(myDog);
    }
    
    return 0;
}
