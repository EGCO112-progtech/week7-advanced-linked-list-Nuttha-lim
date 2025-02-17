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
   char input[100],data[50]; // char entered by user
   int score;

   instructions(); // display the menu
   printf( "%s", "? " );
   scanf( "%u", &choice );
   fflush(stdin);

   // loop while user does not choose 3
   while ( choice != 3 ) { 
      switch ( choice ) { 
         case 1:
            scanf("%d %49[^\n]", &score, data);
            insert( &startPtr, score, data ); // insert item in list
            printList( startPtr );
            printListR(startPtr);
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
                  printList( startPtr );
                  printListR(startPtr);
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
