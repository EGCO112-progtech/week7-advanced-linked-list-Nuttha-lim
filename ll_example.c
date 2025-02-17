// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>
#include "stdlib.h"
#include "ll.h"

int main( void )
{ 
   LLPtr startPtr = NULL; // initially there are no nodes
   unsigned int choice; // user's choice
   char data[50]; // char entered by user
   int score;

   instructions(); // display the menu
   printf( "%s", "? " );
   scanf( "%u", &choice );
   getchar();

   // loop while user does not choose 3
   while ( choice != 3 ) { 
      switch ( choice ) { 
         case 1:
            printf( "Enter a ID and name: " );
            scanf( "%d", &score );
            getchar();
            fgets(data, sizeof(data), stdin);
            data[strcspn(data, "\n")] = 0;

            insert( &startPtr, score, data ); // insert item in list
            printListR(startPtr);
            printList( startPtr );
            
            break;
         case 2: // delete an element
            // if list is not empty
            if ( !isEmpty( startPtr ) ) { 
               printf( "Enter number to be deleted: " );
               scanf( "%d", &score );
               getchar();

               // if character is found, remove it
               if ( deletes( &startPtr, score ) ) { // remove item
                  printf( "%d deleted.\n", score );
                  printListR(startPtr);
                  printList( startPtr );
                  
               } // end if
               else {
                  printf( "%d not found.\n\n", score );
               } // end else
            } // end if
            else {
               puts( "List is empty.\n" );
            } // end else

            break;
         default:
            puts( "Invalid choice.\n" );
            instructions();
            break;
      } // end switch
      printf( "%s", "? " );
      scanf( "%u", &choice );
      getchar();
   } // end while
  /* Clear all nodes at the end of nodes*/
  clearList(&startPtr);
   puts( "End of run." );
} // end main
