#include <string.h>


// self-referential structure
struct Node {
   char data[50]; // each listNode contains a character
   int score;
   struct Node *nextPtr; // pointer to next node
   struct Node *prevPtr;
}; // end structure listNode

typedef struct Node LLnode; // synonym for struct listNode
typedef LLnode *LLPtr; // synonym for ListNode*

// prototypes

int deletes( LLPtr *sPtr, int score);
int isEmpty( LLPtr sPtr );
void insert( LLPtr *sPtr, int score, const char *data);
void printList( LLPtr currentPtr );
void printListR( LLPtr currentPtr );
void instructions( void );
void clearList(LLPtr *sPtr);

void clearList(LLPtr *sPtr)
{
    puts("Clear all nodes");
    while (*sPtr != NULL) {
        printf("delete %d\n", (*sPtr)->score);
        deletes(sPtr, (*sPtr)->score);
    }
}

void printListR( LLPtr currentPtr )
{
   if ( isEmpty( currentPtr ) ) {
      puts( "List is empty.\n" );
   }
   else {
      while ( currentPtr->nextPtr!= NULL ) {
         currentPtr = currentPtr->nextPtr;
      }
      while (currentPtr != NULL) {
         printf("%d %s --> ", currentPtr->score, currentPtr->data);
         currentPtr = currentPtr->prevPtr;
     }
      printf( "NULL\n");
   }
}

// display program instructions to user
void instructions( void )
{
   puts( "Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end." );
} // end function instructions

// insert a new value into the list in sorted order
void insert(LLPtr *sPtr, int score, const char *data)
{
   LLPtr newPtr; // pointer to new node
   LLPtr previousPtr; // pointer to previous node in list
   LLPtr currentPtr; // pointer to current node in list

   newPtr =(LLPtr) malloc( sizeof( LLnode ) ); // create node

   if ( newPtr != NULL ) { // is space available
      newPtr->score = score;
      strcpy(newPtr->data, data);
      newPtr->nextPtr = NULL; // node does not link to another node
      newPtr->prevPtr = NULL;
    
       
      previousPtr = NULL;
      currentPtr = *sPtr;

      // loop to find the correct location in the list
      while ( currentPtr != NULL && (score > currentPtr->score || (score == currentPtr->score && strcmp(data, currentPtr->data) > 0))) {
         previousPtr = currentPtr; // walk to ...
         currentPtr = currentPtr->nextPtr; // ... next node
      } // end while

      // insert new node at beginning of list
      if ( previousPtr == NULL ) {
         newPtr->nextPtr = *sPtr;
         if (*sPtr != NULL) {
            (*sPtr)->prevPtr = newPtr;
        }
      
         *sPtr = newPtr;
        
      } // end if
      else { // insert new node between previousPtr and currentPtr
         previousPtr->nextPtr = newPtr;
         newPtr->prevPtr = previousPtr;
         newPtr->nextPtr = currentPtr;
         if (currentPtr != NULL) {
            currentPtr->prevPtr = newPtr;
         }
 
         
      } // end else
   } // end if
   else {
      printf( "No memory available.\n");
   } // end else
} // end function insert

// delete a list element
int deletes( LLPtr *sPtr, int score )
{
   LLPtr previousPtr; // pointer to previous node in list
   LLPtr currentPtr; // pointer to current node in list
   LLPtr tempPtr; // temporary node pointer
   if (*sPtr == NULL) return 0;

   // delete first node
   if ((*sPtr)->score == score) {
      tempPtr = *sPtr; // hold onto node being removed
      *sPtr = ( *sPtr )->nextPtr; // de-thread the node
      if (*sPtr != NULL) {
         (*sPtr)->prevPtr = NULL;
     }
      free( tempPtr ); // free the de-threaded node
      return 1;
   } // end if
   else {
      previousPtr = *sPtr;
      currentPtr = ( *sPtr )->nextPtr;

      // loop to find the correct location in the list
      while ( currentPtr != NULL && currentPtr->score != score ) {
         previousPtr = currentPtr; // walk to ...
         currentPtr = currentPtr->nextPtr; // ... next node
      } // end while

      // delete node at currentPtr
      if ( currentPtr != NULL ) {
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         if (currentPtr->nextPtr != NULL) {
            currentPtr->nextPtr->prevPtr = previousPtr;
        }
         free( tempPtr );
         return 1;
      } // end if
   } // end else

   return '\0';
} // end function delete

// return 1 if the list is empty, 0 otherwise
int isEmpty( LLPtr sPtr )
{
   return sPtr == NULL;
} // end function isEmpty

// print the list
void printList( LLPtr currentPtr )
{
   // if list is empty
   if ( isEmpty( currentPtr ) ) {
      puts( "List is empty.\n" );
   } // end if
   else {
      puts( "The list is:" );

      // while not the end of the list
      while ( currentPtr->nextPtr!= NULL ) {
         printf("%d %s --> ", currentPtr->score, currentPtr->data);
         currentPtr = currentPtr->nextPtr;
      } // end while

      printf("%d %s --> NULL\n", currentPtr->score, currentPtr->data);
       

     
       
   } // end else
} // end function printList
