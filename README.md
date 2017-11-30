K-means clustering problem

Problem: Given a list of 2-D points in x-y coordinates, and a cluster number, K, 
the task is to partition the input point set to K subsets such that
points in each subset have the minimum distances to the centroid of their own subset then all other subsets' centroids. 

*******************************
I. input/output specifications:
*******************************
A. Input (1): a text file. 
/**The name of the input file should be given in argv[1].
The first text line is the cluster number, K.
The second text line is the dimension (#of rows and # of columns) of the image, follows by a list of points in x-y coordinates.
	For example:
		4	// 4 clusters 
		40  50  // 40 rows and 50 columns of an image
    		12  30 // the pixel is on row 12 and column 30
     		10  21 // the pixel is on row 10 and column 21
    		:	
		:
B. Output-1: A text file. 
// The name of output-1 file should be given in argv[2].
The first text line is the cluster number, K.
The second text line is the dimension (#of rows and # of columns) of the image, follows by the list of input points plus their cluster ID.
For example:
4
	40  50  // 40 rows and 50 columns of an image
    	12  30  2 // the pixel is on row 12 and column 30 and its cluster ID is 2
     	10  21  1 // the pixel is on row 10 and column 21 and its cluster ID is 1
    		:	
		:
C. Output-2: An 2-D image where if a pixel has a label, displays with its label, otherwise, display with a blank.// The name of output-2 file should be given in argv[3].
 
III. Data structure:
1) A point node class with following fields: 
- X-coordinate (integer)
- Y-coordinate (integer)
- ClusterLabel (integer)
- Distance (double) the distance to its own cluster center point
- Next (a node pointer to the next node, initialize to NULL)
- a printNode method to print the info of the node
- a constructor to create a new node of a given data and next should be null.
- a distractor to free a node


	
	2) A linkedList class (with a dummy node), including
	- istHead, points to a dummy node. 
	- a method to do insertion
	- a method to do deletion
	- a printList method to print the entire list
	- a constructors to create the linked list with a dummy node.
		Set the data field of the dummy node to -9999 
	- a distractor to free all nodes in the linked list.

	3) A K-mean class
	- a struct of xycoord
	- X-coordinate (integer)
- Y-coordinate (integer)
	- K(integer)
	- Kcentroids[K] of xycoord 
	- listHead (linked list)
	- numRow (integer)
	- numCol (integer)
	- imageArray // a 2-D integer array that is dynamically allocated
	- kMean clustering method
	- displayImage method

IV) kMeans clustering Algorithm

step 0:  K, numRow, numCol  get from input file.

	   Kcentroids[K]  Dynamically allocate the K centroids
 
listHead  Create a linked list for the input point set, where listHead  points to a dummy node.

imageArray  Dynamically allocate a 2-D arrays.
	   
step 1: Assign each point in the linked list to a label, from 1 to K.

step 2: Output the 2-D array of pixels with their labels in output-1 file.
	(** pixel without label will display as a blank.)

step 3: Go thru the entire linked list to compute the centroids of the K  clusters. Store the centroids in each Kcentroids[i], i from 1 to K.
(** You should be able to compute the K centroids just go thru the linked list only once.)

step 4: 4.1: for each point, p, in the linked list
	   	compute the distance, di(p,ci), from 
			p to the centroids of each Kcentroids[i], i = 1 to K
	   4.2: min_i <-- determine which di(p,ci) is minimum
		
	   4.3: if min_i is not the same as p's old label change p's label to min_i 

step 5: repeat step 4 until all points in the linked list are checked.
            
step 6: repeat step 2 to step 5 until no point changes its label.

Step 7: Output the info of points in the linked list to Output-2 file.

