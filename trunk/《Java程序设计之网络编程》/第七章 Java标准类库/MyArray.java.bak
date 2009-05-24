//20090515 by Yishi Guo
//
class Node {
	Object data;
	Node next;
	Node(Object value) {
		data = value;
	}
	
	public String toString() {
		return data.toString();
	}
}

public class MyArray {
	private Node header = new Node(null);
	private Node pointer = new Node(null);
	
	private int size = 0;
	
	public int size() {
		return size;
	}
	
	/////////////////// add ///////////////////////
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
	private void addAfter(Node newNode, Node node) {
		node.next = newNode;
		newNode.next = null;
		pointer = newNode;
		size++;
	}
	
	///////// get ///////////////////////////////
	public Object get(int index) {
		return getNode(index).data;
	}
	
	private Node getNode(int index) {
		Node node = header;
		if (index < 0 || index > size) {
			//do throws ... ...
			System.out.println(node + " " + header + " dd");
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
	public void clear() {
		int i = 0;
		while (i < size) {
			remove(i);
		}
	}
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
	private void insertNode(Node newNode, Node nodePrev, Node nodeNext) {
		nodePrev.next = newNode;
		newNode.next = nodeNext;
		size++;
	}
	
	////////////////// set //////////////////////
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
}
