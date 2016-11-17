package huffman;

public class Huffman {
	MinHeap minHeap;
	Node huffNode ;
	String[] code = new String[27];
	int n;
	public Huffman(MinHeap minHeap) {
		this.minHeap= minHeap; 
		this.n = minHeap.size();
		makeHuffman();
		this.huffNode = minHeap.array[1];
	}
	
	Node makeHuffman(){
		
		for(int i=1; i<n; i++){
			Node newNode = new Node();
			newNode.left = minHeap.pop();
			newNode.right = minHeap.pop();
			newNode.letter = '\0';
			newNode.freq = newNode.left.freq + newNode.right.freq;
			minHeap.push(newNode);
		}
		return minHeap.array[1];
	}
	void makeTableSet(){
		
		String start = "";
		makeTable(huffNode, start);
	}
	
	void makeTable(Node huffNode, String s){
		
		if(huffNode.letter=='\0'){
			String a = s +"0";
			String b = s +"1";
			makeTable(huffNode.left, a);
			makeTable(huffNode.right, b);
		}else{
			int index = (int)(huffNode.letter)-97;
			if(index<0)code[26] = s.toString();
			else code[index] = s.toString(); 
		}	
	}
	void makeTreeSet(){
		Node huffNode = new Node();
		this.huffNode = huffNode;
		for(int i =0; i<27;i++){
			huffNode = this.huffNode;
			for(int j=0; j<code[i].length(); j++){
				if(code[i].charAt(j) == '0'){
					if(huffNode.left == null){
						huffNode.left = new Node();
					}
					huffNode = huffNode.left;
				}else{
					if(huffNode.right == null){
						huffNode.right = new Node();
					}
					huffNode = huffNode.right;
				}
			}
			char input = (char)(i +97);
			if(input == '{')huffNode.letter = ' ';
			else huffNode.letter = input;
		}
		
	}
}
