package huffman;

public class MinHeap {
		Node array[] = new Node[100];
		int size = 0;
		int l,r; 
		int smallest;
		
		void buildMinHeap(){
			for(int i=size; i>=1; i--){
				minHeapify(i);
			}
		}
		int size(){
			return this.size;
		}
		void minHeapify(int i){
			l = 2*i;
			r = 2*i + 1;
			if(l <= size&&array[l].freq < array[i].freq){
				smallest = l;
			}
			else{
				smallest = i;
			}
			if(r <= size&&array[r].freq < array[smallest].freq){
				smallest = r;
			}
			if(smallest!=i){
				swap(i,smallest, array);
				minHeapify(smallest);
			}
		}
		void push(Node x){
			size++;
			array[size] = x;
			buildMinHeap();
		}
		Node pop(){
			if(isEmpty())return null;
			Node top = array[1];
			swap(1,size,array);
			array[size] =null; size--;
			buildMinHeap();
			return top;
		}
		boolean isEmpty(){
			return size==0;
		}
		void swap(int i, int j, Node[] array){
			Node tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
}

