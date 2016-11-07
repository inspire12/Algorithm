
public class Node {
	int key; String value; 
	public Node(int key, String value) {
		this.key = key;
		this.value = value;
	}
	public void modifyKey(int x){
		this.key = x;
	}
	@Override
	public String toString() {
		return ""+this.key;
	}
	
}
