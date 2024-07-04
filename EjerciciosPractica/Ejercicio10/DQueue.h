#ifndef _DQUEUE
   #define _DQUEUE

        typedef int element;

		typedef struct nodeQD{
			element e;
			struct nodeQD *next;
		}NodeQD;

		typedef struct queueD{
			NodeQD *head;
			NodeQD *tail;
		}QueueD;

		void create(QueueD *Q);
		void enqueue(QueueD *Q,element ele);
		int isEmpty(QueueD Q);
		element dequeue(QueueD *Q);
		void deleteDQ(QueueD *Q);

   
#endif   