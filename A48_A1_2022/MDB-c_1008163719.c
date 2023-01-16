/*
 *  CSC A48 - Winter 2022 - Assignment 1 starter
 * 
 *  (c) 2020-22 Francisco Estrada
 *  - No part of this code may be reproduced without written authorization
 * 
 * This is the file where you will be doing most of your work. The
 * functionality you must provide for part 1 of the assignment is described
 * in the handout. Given in detail in the comments at the head of each
 * function below. 
 * 
 * Plan your work carefully, review the notes for Unit 3, and work carefully
 * to complete the functions in this file. You can bring 
 * questions to your TAs or instructors during office hours. Please
 * remember:
 * 
 * - You should not share any part of your solution in any form
 * - You should not post any assignment code on Piazza
 * - You should definitely *help* other understand any ideas and
 *   concepts regarding linked lists that you have already mastered,
 *   but being careful not to give away parts of the solution, or
 *   descriptions of how to implement functions below.
 * - If you are not sure whether you can or can not discuss some
 *   particular aspect of the work to be done, remember it's always 
 *   safe to talk with your TAs.
 * - Obtaining external 'help' including being given code by an
 *   external party, or being tutored on how to solve
 *   the assignment constitutes an academic offense.
 * 
 * All tasks to be completed by you are clearly labeled with a
 * ***** TO DO ****** comment block, which also gives you details
 * about what you have to implement. Look carefully and make sure
 * you don't miss a thing!
 * 
 * NOTE: This file contains no main() function! you can not compile
 * it on its own to create an executable. It's meant to be used
 * together with Part1_driver.c - be sure to read that file carefully
 * to understand how to use the tests there - Any additional tests
 * you want to run on the code below should be added to Part1_driver.c
 * 
 * Before you even get starter implementing, please complete the
 * student identification section below, and check that you are aware
 * of the policy on academic honesty and plagiarism.
 */

/* Student identification:
 * 
 * Student Name (Last name, First name): Chen, Ruofan
 * Student Number: 1008163719
 * UTORid: chenr103
 * Your instructor's name is: Marcelo Ponce Castro
 */

/* Academic Integrity Statement:
 * 
 * I hereby certify that the work contained in this file is my own, and
 * that I have not received any parts of my solution from other sources
 * including my fellow students, external tutoring services, the internet,
 * or algorithm implementations found online.
 * 
 * Sign here with your name:
 *
 *	Ruofan Chen  
 */

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 1024

/* Compound data type declarations */
/***************************************************************************/
/******                         TO DO                               ********/
/****** In the space below, complete the definitions of the compound *******/
/****** data types that will be needed to implement the movie review *******/
/****** linked list. This includes the MovieReview type, and the     *******/
/****** ReviewNode. Details about the contents of these can be       *******/
/****** found in the assignment handout. Read them carefully!        *******/
/******                                                              *******/
/****** AFTER completing the basic linked list, complete the CDT     *******/
/****** required to implement a list for the movie's cast.           *******/
/***************************************************************************/

typedef struct castList_struct
{    
	char name[MAX_STR_LEN];
	float salary;
	struct castList_struct *next;
} CastList;

typedef struct castList2_struct
{
	/*
     * This is a self-declared CDT; this list intends to store all stars,
	 * the number of movies they are in, and the total earnings of him/her.
     */
	char name[MAX_STR_LEN];
	float involved_movies;
	float total_earnings;
	struct castList2_struct *next;
    
} CastList2;

typedef struct movieReview_struct
{
	char movie_title[MAX_STR_LEN];
	char movie_studio[MAX_STR_LEN];
	int year; // Will be in range [1920, 2999]
	float BO_total;
	int score; // Will be in range [0, 100]
	CastList *cast;
} MovieReview;

typedef struct reviewNode_struct
{
	MovieReview review;
	struct reviewNode_struct *next;
} ReviewNode;

ReviewNode *newMovieReviewNode()
{
    /*
     * This function allocates an empty ReviewNode, and initializes the
     * contents of the MovieReview for this node to reasonable (uninitialized) values.
     * The fields in the MovieReview should be set to:
     *  movie_title=""
     *  movie_studio=""
     *  year = -1
     *  BO_total = -1
     *  score = -1
     *  cast = NULL;
     * 
     * The *next pointer for the new node MUST be set to NULL
     * 
     * The function must return a pointer to the newly allocated and initialized
     * node. If something goes wrong, the function returns NULL
     */
 
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

	
    ReviewNode *new_node=NULL;
	new_node =(ReviewNode *)calloc(1, sizeof(ReviewNode));
	
	strcpy(new_node->review.movie_title,"");
	strcpy(new_node->review.movie_studio,"");
	new_node->review.year=-1;
	new_node->review.BO_total=(float)-1;
	new_node->review.score=-1;
	new_node->review.cast=NULL;
	
	new_node->next=NULL;

    return(new_node);   
}

ReviewNode *findMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head)
{
    /*
     * This function searches through the linked list for a review that matches the input query. 
     * The movie review must match the title, studio, and year provided in the 
     * parameters for this function.
     * 
     * If a review matching the query is found, this function returns the address of the node that
     * contains that review. 
     * 
     * If no such review is found, this function returns NULL
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
	
	ReviewNode *traverse = head;
	while(traverse != NULL){
		if((strcmp(traverse->review.movie_title, title) == 0) && (strcmp(traverse->review.movie_studio, studio) == 0) && (traverse->review.year == year)){
			return traverse;
		}
		traverse = traverse->next;
	}
	
    return NULL; 
}

ReviewNode *insertMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function inserts a new movie review into the linked list.
     * 
     * The function takes as input parameters the data neede to fill-in the review,
     * as well as a pointer to the current head of the linked list.
     * 
     * If head==NULL, then the list is still empty.
     * 
     * The function inserts the new movie review *AT THE HEAD* of the linked list,
     * and returns the pointer to the new head node.
     * 
     * The function MUST check that the movie is not already in the list before
     * inserting (there should be no duplicate entries). If a movie with matching
     * title, studio, and year is already in the list, nothing is inserted and the
     * function returns the current list head.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
	if (!findMovieReview(title, studio, year, head)){ // If the list is not null & movie is found in list
		ReviewNode *new_node = newMovieReviewNode();
		strcpy(new_node->review.movie_title, title);
		strcpy(new_node->review.movie_studio, studio);
		new_node->review.year=year;
		new_node->review.BO_total=(float)BO_total; // assuming that BO_total can be negative for films that lose money
		new_node->review.score=score;
		new_node->next=head;
		return new_node;
	}
	else if (!(head)){ // If the list is not empty/movie found in list
		printf("The movie is already in the Database\n");
	}
    return head;
}

int countReviews(ReviewNode *head)
{
  /*
   * This function returns the number of reviews. 
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
	
	int counter = 0;
	ReviewNode *traverse = head;
	while(traverse != NULL){
		counter++;
		traverse = traverse->next;
	}
    return counter;
}

void updateMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function looks for a review matching the input query [title, studio, year].
     * If such a review is found, then the function updates the Box-office total, and the score.
     * If no such review is found, the function prints out 
     * "Sorry, no such movie exists in the database"
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
	ReviewNode *target = findMovieReview(title, studio, year, head);
	
	if (target){
		target->review.BO_total=(float)BO_total;
		target->review.score=score;
	}
	else{
		printf("Sorry, no such movie exists in the database\n");
	}
	
}

ReviewNode *deleteMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN],int year, ReviewNode *head)
{
    /*
     * This function removes a review matching the input query from the database. If no such review can
     * be found, it does nothing.
     * 
     * The function returns a pointer to the head of the linked list (which may have changed as a result
     * of the deletion process)
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *target = findMovieReview(title, studio, year, head);
	
	if (target){
		if (target == head){
			ReviewNode *newHead = head->next;
			free(head);
			return newHead;
		}
		ReviewNode *traverse = head->next;
		ReviewNode *previous = head;
		while(traverse != NULL){
			if (traverse == target){
				previous->next = traverse->next;
				free(traverse);
				return head;
			}
			traverse = traverse->next;
			previous = previous->next;
		}
	}
	
    return head;
}

float printMovieReviews(ReviewNode *head)
{
    /*
     * This function prints out all the reviews in the database, one after another.
     * Each field in the review is printed in a separate line, with *no additional text*
     * (that means, the only thing printed is the value of the corresponding field).
     * 
     * Reviews are separated from each other by a line of
     * "*******************"

     * The function also computes and returns the Box-office total, for all the
     * movies that match the query.
     * 
     * See the A1 handout for a sample of the output that should be produced
     * by this function
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
	
	float total = 0;
	ReviewNode *traverse = head;
	while(traverse != NULL){
		printf("%s\n%s\n", traverse->review.movie_title, traverse->review.movie_studio);
		printf("%d\n%f\n%d\n", traverse->review.year, (float)traverse->review.BO_total, traverse->review.score);
		printf("*******************\n");
		total += (float)traverse->review.BO_total;
		traverse = traverse->next;
	}
    return total;
}

float queryReviewsByStudio(char studio[MAX_STR_LEN], ReviewNode *head)
{
    /*
     * This function looks for reviews whose studio matches the input query.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     * 
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  
    
	float total = 0;
	ReviewNode *traverse = head;
	while(traverse != NULL){
		if (!strcmp(traverse->review.movie_studio, studio)){
			printf("%s\n%s\n", traverse->review.movie_title, traverse->review.movie_studio);
			printf("%d\n%f\n%d\n", traverse->review.year, (float)traverse->review.BO_total, traverse->review.score);
			printf("*******************\n");
			total += (float)traverse->review.BO_total;
		}
		traverse = traverse->next;
	}
    return total;
}

float queryReviewsByScore(int min_score, ReviewNode *head)
{
    /*
     * This function looks for reviews whose score is greater than, or equal to
     * the input 'min_score'.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     * 
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  
    
	float total = 0;
	ReviewNode *traverse = head;
	while(traverse != NULL){
		if (traverse->review.score >= min_score){
			printf("%s\n%s\n", traverse->review.movie_title, traverse->review.movie_studio);
			printf("%d\n%f\n%d\n", traverse->review.year, (float)traverse->review.BO_total, traverse->review.score);
			printf("*******************\n");
			total += traverse->review.BO_total;
		}
		traverse = traverse->next;
	}
    return total;
}

ReviewNode *deleteReviewList(ReviewNode *head)
{
  /*
   * This function deletes the movie review database, releasing all the
   * memory allocated to the nodes in the linked list.
   * 
   * Returns a NULL pointer so that the head of the list can be set to NULL
   * after deletion.
   */
      
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/    

    ReviewNode *traverse = head;
	ReviewNode *next;
	
	while(traverse != NULL){
		next = traverse->next;
		free(traverse);
		traverse = next;
	}
    return traverse;
}

/* CRUNCHY SECTION! Do not work on the functions below until
 * your basic linked list is working properly and is fully tested!
 */ 

ReviewNode *swapReview(ReviewNode *previous, ReviewNode *current, ReviewNode *nextRev){
  /*
   * This function swaps the current & nextRev  reviews given.
   * The function then returns the pointer to the new "middle" review, which is nextRev.
   * Example: A -> B -> C -> ...(becomes)... A -> C -> B -> ; C is then returned.
   */
   
   current->next = nextRev->next; // B's tail to becomes what was C's tail
   previous->next = nextRev; // A's tail becomes C
   nextRev->next = current; // C's tail becomes B
   return nextRev;
}

ReviewNode *swapReviewHead(ReviewNode *current, ReviewNode *nextRev){
  /*
   * This function swaps (interchange order in list) the 2 reviews given.
   * These two reviews are the current first 2 reviews of the list.
   * The function then returns the pointer to the new first review, which is nextRev.
   * Example: A -> B -> ...(becomes)... B -> A -> ; B is then returned.
   */
   current->next = nextRev->next; // A's tail becomes what was B's tail
   nextRev->next = current; // B's tail becomes A
   return nextRev; // Return B, the review that should be in front now
}

ReviewNode *sortReviewsByTitle(ReviewNode *head)
{
  /*
   * This function sorts the list of movie reviews in ascending order of movie
   * title. If duplicate movie titles exist, the order is arbitrary (i.e. you
   * can choose which one goes first).
   * 
   * However you implement this function, it must return a pointer to the head
   * node of the sorted list.
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
	
	int length = countReviews(head);
	ReviewNode *headSorted = head; // A variable that stores the current head.
	
	if(length > 1){ // If some sorting is required...
		ReviewNode *current, *nextRev, *previous;
		
		for(int i = 2; i <= length; i++){
			// When length == 2, then first two might be swapped.
			current = headSorted;
			nextRev = current->next;
			if (strcmp(current->review.movie_title, nextRev->review.movie_title) > 0){
				current = swapReviewHead(current, nextRev);
				// Adjustment after swapping.
				headSorted = current; // Current head stored.
				nextRev = current->next; // Next of current updated.
			}
			
			// When length > 2, 3 pointers are needed in swapping.
			// To use previous, the other 2 pointers are "incremented".
			previous = current;
			current = current->next;
			nextRev = nextRev->next;
			for(int j = 3; j <= length; j++){
				if (strcmp(current->review.movie_title, nextRev->review.movie_title) > 0){
					current = swapReview(previous, current, nextRev);
					// Adjustment after swapping.
					nextRev = current->next; // Next of current updated.
				}
				// Increment if needed...
				previous = current;
				current = current->next;
				nextRev = nextRev->next;
			}
		}
	}
	
    return headSorted;
}

void insertCastMember(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head, char name[MAX_STR_LEN], float salary)
{
  /*
   * This function inserts the name of a cast member for the given movie into the
   * linked list of cast members. The new cast member must go to the end of the list.
   * 
   * Duplicate names are allowed - this time! 
   * 
   * Notice the function receives the title, studio, and year for the movie, as
   * well as a pointer to the movie DB linked list. The function must find the 
   * correct movie and if such a movie exists, add the cast member's name to its
   * cast list.
   * 
   * If no such movie is found, this function does nothing.
   * 
   * You're free to add helper functions to insert the cast member's name
   * into the cast list.
   */   

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/      
	
	ReviewNode *given_movie = findMovieReview(title, studio, year, head);
	
	if(given_movie){
		CastList *new_cast =(CastList *)calloc(1, sizeof(CastList));
		strcpy(new_cast->name, name);
		new_cast->salary = (float)salary;
		new_cast->next=NULL;
		
		CastList *cast_head = given_movie->review.cast;
		if(cast_head){ // If the list of cast is not empty
		    CastList *traverse = cast_head;
			while(traverse->next != NULL){
				traverse = traverse->next;
			}
			traverse->next = new_cast;
		}
		else{
			given_movie->review.cast = new_cast;
		}
	}
}

CastList2 *findCastMember(char name[MAX_STR_LEN], CastList2 *head){
    /*
     * This function searches through the linked list CastList2 for a 
	 * cast member with the given name. 
     * 
     * If a matching cast is found, this function returns the address of the node that
     * contains that cast. 
     * 
     * If no such casts is found, this function returns NULL
     */

	CastList2 *traverse = head;
	while(traverse != NULL){
		if(strcmp(traverse->name, name) == 0){
			return traverse;
		}
		traverse = traverse->next;
	}
    return NULL; 
}

CastList2 *insertMemberToCastList2(char name[MAX_STR_LEN], float total_earnings, CastList2 *head){
    /*
     * This function creates a new CastList2 with the given values. 
	 * Then, the new CastList2 node is inserted to the CastList2 list at the TAIL.
	 *
	 * The *next pointer for this new node is set to NULL.
     */
	
    CastList2 *new_node = (CastList2 *)calloc(1, sizeof(CastList2));
	
	strcpy(new_node->name, name);
	new_node->involved_movies=(float)1;
	new_node->total_earnings=total_earnings;
	new_node->next=NULL;
	
	CastList2 *traverse = head;
	if (traverse){
		while((traverse != NULL) && (traverse->next != NULL)){
			traverse = traverse->next;
		}
		
		traverse->next = new_node;
	}
	else{
		head = new_node;
	}
	
	return head;
}

void whosTheStar(ReviewNode *head)
{
  /*
   *  This function goes through the movie database and determines who is
   * the cast members whose movies have the greatest average earnings.
   *
   * Earnings are defined as the box office total minus the salaries of all
   * cast members involved with the movie.
   *
   *  You're free to implement this function however you like, use any of
   * the code you wrote for other parts of the assignment, and write any
   * helper functions that you need. But:
   *
   *  You can not import extra libraries (no additional #include), and
   * all the implementation here should be your own. 
   *
   *  The function simply prints out:
   *
   *  Name of cast member
   *  Average movie earnings (as a floating point number)
   *
   *  For the cast member whose movies make the greatest average earnings
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/      

	// Using a self-declared CDT named CastList2, which is a list of all cast in
	// this database.
	
	float earnings;
	ReviewNode *traverse_movie = head;
	CastList2 *all_cast = NULL; // (CastList2 *)calloc(1, sizeof(CastList2))
	CastList *traverse_cast;
	
	
	while(traverse_movie != NULL){
		// Calculating the earnings of this movie
		traverse_cast = traverse_movie->review.cast;
		earnings = traverse_movie->review.BO_total;
		while(traverse_cast != NULL){
			earnings -= traverse_cast->salary;
			traverse_cast = traverse_cast->next;
		}
		// Updating all_cast with potential new cast members
		// and the newly calculated earnings of the movie.
		traverse_cast = traverse_movie->review.cast;
		while(traverse_cast != NULL){
			CastList2 *temp_cast = findCastMember(traverse_cast->name, all_cast);
			if(temp_cast){ // If cast member already in list
				temp_cast->involved_movies += (float)1;
				temp_cast->total_earnings += earnings;
			}
			else{
				all_cast = insertMemberToCastList2(traverse_cast->name, earnings, all_cast);
			}
			traverse_cast = traverse_cast->next;
		}
		traverse_movie = traverse_movie->next;
	}
	
	if(all_cast){ // If there are cast in this database
		// Finding the max average earnings amongst the cast members
		CastList2 *traverse = all_cast;
		float max_avg = (traverse->total_earnings/traverse->involved_movies);
		traverse = traverse->next;
		while(traverse != NULL){
			if ((traverse->total_earnings/traverse->involved_movies) > max_avg){
				max_avg = (traverse->total_earnings/traverse->involved_movies);
			}
			traverse = traverse->next;
		}
		
		// Printing out people with this max average earnings
		traverse = all_cast;
		while(traverse != NULL){
			if ((traverse->total_earnings/traverse->involved_movies) == max_avg){
				printf("%s%f\n", traverse->name, max_avg);
			}
			traverse = traverse->next;
		}
	}
	else{
		printf("there are no cast found...\n"); // Warns if there are no cast in database
	}
	
}