

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.StringTokenizer;


public class Main {
	private static AppView appView;
	private static BufferedReader br;
	private static int size;
	private static Scanner scan;
	public static void main(String[] args) throws IOException {
		appView = new AppView();
		MaxHeap maxHeap = new MaxHeap(10);
		Node[] inputData = fileInput();
		for(int i=0; i<size; i++){
			maxHeap.insert(inputData[i]);
		}
		boolean check =true;
		maxHeap.print();maxHeap.printMenu();
		while(check){
			scan = new Scanner(System.in);
			switch (scan.nextInt()) {
			case 1:
				appView.Case1PrintNewJob();
				String job= scan.next();
				appView.Case2PrintPriority();
				int add  = scan.nextInt();
				Node newNode = new Node(add,job);
				maxHeap.insert(newNode);
				break;
			case 2:
				System.out.println("Max : "+maxHeap.data[0].key+", "+maxHeap.data[0].value);
				break;
			case 3:
				maxHeap.extract_max();
				appView.Case3SuccesJob();
				break;
			case 4:
				appView.Case4ModifyNode();
				int x = scan.nextInt();
				appView.Case4ModifyKey();
				int in = scan.nextInt();
				maxHeap.increase_key(x, in);
				break;
			case 5:
				appView.Case5DeleteNode();
				int del = scan.nextInt();
				maxHeap.delete(del);
				break;
			case 6:
				check = false;
				appView.Case6Terminate();
				maxHeap.print();
				return ;
			default:
				break;
			}
			maxHeap.print();
			maxHeap.printMenu();
		}
	}

	
	
	static Node[] fileInput() throws IOException{
		Node[] data = new Node[20];
		br = new BufferedReader(new FileReader("data03.txt"));
		String input = br.readLine(); int i=0;
		while(input!=null){
			StringTokenizer st = new StringTokenizer(input, ", ");
			int key = Integer.parseInt(st.nextToken()); 
			String value = st.nextToken();
			data[i] = new Node(key, value); i++;
			input = br.readLine();
		}
		size = i;
		return data;
	}
	
}