//20090515 by Yishi Guo
//Modified: 20090518

// Node Class
class Node {
	Object data;
	Node next;
	Node(Object value) {
		data = value;
	}
	
	//Reconstruct toString Function
	public String toString() {
		return data.toString();
	}
}

//MyArray Class
public class MyArray {
	private Node header = new Node(null);	//Point Header Node
	private Node pointer = new Node(null);	//Point the current Node
	
	private int size = 0;	//Save the length of the MyArray
	
	//Get the MyArray size
	public int size() {
		return size;
	}
	
	/////////////////// add ///////////////////////
	
	//Add Object
	public boolean add(Object o) {
		if (size == 0) {
			header = new Node(o);
			header.next = null;
			pointer = header;
			size++;
		}
		else {
			addAfter(new Node(o), pointer);
		}
		return true;
	}
	
	//Add newNode after node
	private void addAfter(Node newNode, Node node) {
		node.next = newNode;
		newNode.next = null;
		pointer = newNode;
		size++;
	}
	
	///////// get ///////////////////////////////
	
	//Get the Object at index
	public Object get(int index) {
		return getNode(index).data;
	}
	
	//Get the node at index
	private Node getNode(int index) {
		Node node = header;
		if (index < 0 || index > size) {
			//do throws ... ...
		}
		else {
			int i = 0;
			while (i != index) {
				node = node.next;
				i++;
			}
		}
		return node;
	}
	
	////////////////// remove /////////////////////
	
	//Clear all Object
	public void clear() {
		int i = 0;
		while (i < size) {
			remove(i);
		}
	}
	
	//Remove one Object at index
	public void remove(int index) {
		if (index == 0) {
			Node node = header;
			header = node.next;
			
		}
		else if (index == size) {
			int i = 0;
			Node node = header;
			while (i != size - 1) {
				node = node.next;
				i++;
			}
			pointer = node;
			node.next = new Node(null);
		}
		else {
			removeNode(index);
		}
		
		size--;
	}
	
	//Remove node at index
	private void removeNode(int index) {
		int i = 0;
		Node node = header;
		Node nodePrev = node;
		while (i != index) {
			nodePrev = node;
			node = node.next;
			i++;
		}
		
		nodePrev.next = node.next;
	}
	
	//////////// insert //////////////////////
	
	//Insert an Object at index
	public boolean insert(int index, Object o) {
		Node node = header;
		int i = 0;
		while (i != index) {
			node = node.next;
			i++;
		}
		if (size == 0 || index == size) {
			this.addAfter(new Node(o), node);
		}
		else {
			Node nodeNext = node.next;
			this.insertNode(new Node(o), node, nodeNext);
		}
		return true;
	}
	
	//Insert newNode after nodePrev before nodeNext
	private void insertNode(Node newNode, Node nodePrev, Node nodeNext) {
		nodePrev.next = newNode;
		newNode.next = nodeNext;
		size++;
	}
	
	////////////////// set //////////////////////
	
	//Set the index of Object o
	public boolean set(int index, Object o) {
		Node node = header;
		int i = 0;
		while (i != index) {
			node = node.next;
			i++;
		}
		node.data = o;
		return true;
	}
	
	////////////// toString ///////////////////20090518
	
	//Get the String of MyArray
	public String toString() {
		String str = ""; 
		int i = 0;
		while (i != this.size()) {
			str += getNodeStr(i) + " ";
			i++;
		}
		
		return str;
	}
	
	//Get the String of node at index
	private String getNodeStr(int index) {
		String nodeStr = getNode(index).toString();
		
		return nodeStr;
	}
}