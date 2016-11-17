package huffman;

public class Node {
	int freq;
	char letter;
	Node left, right;
	public Node() {
	}
	public Node(int freq, char letter) {
		this.freq = freq;
		this.letter = letter;
	}
	public Node(int freq, Node left, Node right){
		this.freq = freq;
		this.left = left;
		this.right = right;
	}
	@Override
	public String toString() {
		String ret = ""+this.freq + this.letter;
		return ret;
	}
}
