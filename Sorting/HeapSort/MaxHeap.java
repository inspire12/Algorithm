
public class MaxHeap {
	int size =0; 
	Node data[]; int argumentSize=10;
	public MaxHeap(int size) { //buildMaxHeap
		this.argumentSize = size;
		data = new Node[argumentSize];
	}
	public void print(){
		for(int i=0; data[i]!=null ;i++){
			System.out.println(" "+data[i].key +", "+ data[i].value);
		}
		
	}
	public void printMenu(){
		System.out.println("-----------------------------------------------------");
		System.out.println("1. 작업 추가   2. 최대값   3. 최대 우선순위 작업 처리");
		System.out.println("4. 원소 키값 증가          5. 작업 제거        6.종료");
		System.out.println("-----------------------------------------------------");
	}
	private void resize(){
		Node originalData[] = data;
		data = new Node[data.length+argumentSize];
		for(int i =0; i<size; i++){
			data[i] = originalData[i];
		}
	}
	void buildMaxHeap(){
		for(int i=size/2; i>=0; i-- ){
			MaxHeapify(i);
		}
	}
	void MaxHeapify(int i){
		int largest;  
		int left = LeftChild(i);
		int right = RightChild(i);
		if(i==0){left=1;right=2;}
		if(left<size && data[left].key>data[i].key){
			largest = left; 
		}else{
			largest = i;
		}
		if(right<size && data[right].key>data[largest].key){
			largest = right;
		}
		if(largest!=i){
			Node tmp = data[largest];
			data[largest] = data[i];
			data[i] = tmp;
			MaxHeapify(largest);
		}
	}
	public void insert(Node x){
		if(data.length<size){
			resize();
		}
		data[size] = x;
		size++;
		buildMaxHeap();
	}
	public Node max(){
		return data[0];
	}
	public void extract_max(){
		delete(0);
	}
	public void increase_key(int x, int k){
		if(x==0){System.out.println("Error 잘못된 입력"); return ;}
		data[x-1].modifyKey(k);
		buildMaxHeap();
	}
	public void delete(int x){
		if(size==0){System.out.println("**** Error : 힙이 존재하지 않습니다 ****");return ;}
		if(x==0){System.out.println("**** Error : 입력이 잘못되었습니다. ****");return ;}
		data[x-1] = data[--size];
		data[size] = null;
		
		buildMaxHeap();
	}
	
	private int LeftChild(int i){
		if(2*i+1>data.length) resize();
		return 2*i+1;
	}
	private int RightChild(int i){
		if(2*i+2>data.length) resize();
		return 2*i +2;
	}
}
