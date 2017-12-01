import java.util.ArrayList;
import java.util.List;
public class HashMap<Key, Value> {

	public class Node<Key, Value> {
		Key key;
		Value value;

		Node<Key, Value> next;

		public Node(Key k, Value v) {
			this.key = k;
			this.value = v;
			this.next = null;
		}
	}

	List<Node<Key, Value> > Map;
	private int N;

	public HashMap(int n) {
		N = n;
		Map = new ArrayList<Node<Key, Value> >(N + 1);

		for (int i = 0; i < n; i++)
			Map.add(null);

	}

	public void put(Key k, Value v) {
		int loc = (Math.abs(k.hashCode())) % N;

		Node<Key, Value> newNode = new Node<Key, Value>(k, v);
		newNode.next = Map.get(loc);
		Map.set(loc, newNode);
	}

	public Value get(Key k) {
		int loc = Math.abs(k.hashCode()) % N;

		Node<Key, Value> crawl = Map.get(loc);
		while (crawl != null) {
			if (crawl.key == k)
				return crawl.value;
			crawl = crawl.next;
		}

		return null;
	}

	public boolean contains(Key k) {
		int loc = Math.abs(k.hashCode()) % N;

		Node<Key, Value> crawl = Map.get(loc);
		while (crawl != null) {
			if (crawl.key == k)
				return true;
			crawl = crawl.next;
		}
		return false;
	}

	public static void main(String[] args) {
		HashMap <String, Integer> Map = new HashMap<>(5);

		Map.put("abc", 123);
		Map.put("brt", 345);
		Map.put("cio", 678);

		if (Map.contains("brt") == true)
			System.out.println(Map.get("brt"));
		else
			System.out.println("Key doesn't exists");

		if (Map.contains("ger") == true)
			System.out.println(Map.get("ger"));
		else
			System.out.println("Key doesn't exists");

	}
}
