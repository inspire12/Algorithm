package huffman;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Main {
	

	@SuppressWarnings("resource")
	public static void main(String[] args) throws IOException {
		BufferedReader rd = new BufferedReader(new FileReader("data10.txt"));
		String line = rd.readLine();
		rd.close();
		int freqTable[] = new int[27];
		
		for(int i=0; i<line.length(); i++){
			int index =(int)line.charAt(i) - 97;
			if(index<0) freqTable[26]++;
			else freqTable[index]++;
		}
		MinHeap minHeap = new MinHeap();
		for(int i=0; i<27; i++){
			char input = (char)(i+97);
			Node newNode;
			if(input =='{'){
				newNode= new Node(freqTable[i], ' ');
			}else{
				newNode = new Node(freqTable[i], input);
			}
			minHeap.push(newNode);
		}
		Huffman huffman = new Huffman(minHeap);
		huffman.makeTableSet();
		FileWriter fw = new FileWriter("hw08_01_201203431_table.txt");
		//huffman.printTable(fw);
		String table = String.format(" ,%s\n",huffman.code[26]);
		for(int i=0; i<26;i++){
			char s = (char) ('a'+i);
			table += String.format("%c,%s\n",s,huffman.code[i]);
		}
		fw.write(table);
		fw.close();
	//encoded
		fw = new FileWriter("hw08_01_201203431_encoded.txt");
		StringBuffer encode = new StringBuffer();
		for(int i=0; i<line.length(); i++){
			int index =(int)line.charAt(i) - 97;
			if(index == -65)encode.append(huffman.code[26]);
			else encode.append(huffman.code[index]);
		}
		fw.write(encode.toString());
		fw.close();
	//decoded
		rd = new BufferedReader(new FileReader("data10_table.txt"));
		String delimiter = ",";
		String[] str;
		String tb = rd.readLine();
		huffman = new Huffman(minHeap);
		while(tb != null){
			//parsing
			str = tb.split(delimiter);
			
			if(str[0].equals(" ")) huffman.code[26] = str[1];
			else {
				int index = (int)str[0].charAt(0) -97;
				if(index<0) huffman.code[26] = str[1];
				else huffman.code[index] = str[1];
			}
			tb = rd.readLine();
		}
		huffman.makeTreeSet();
		rd = new BufferedReader(new FileReader("data10_encoded.txt"));
		fw = new FileWriter("hw08_01_201203431_decoded.txt");
		//
		line = rd.readLine();
		StringBuffer sb = new StringBuffer();
		Node a = huffman.huffNode;
		for(int i=0; i<line.length(); i++){
			char k = line.charAt(i);
			if(k=='0'){
				a = a.left;
			}else{
				a = a.right;
			}
			if(a.letter!='\0'){
				sb.append(a.letter);
				a = huffman.huffNode;
			}
		}
		fw.write(sb.toString());
		System.out.println(sb.toString());
		fw.close();
		rd.close();
	}

}
