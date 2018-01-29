# tarjan_DFS
#Implementation of Tarjan’s algorithm using depth-first search (DFS) for finding strongly connected components (SCC) in a graph. 

This is the standard algorithm for finding the strongly connected components in a graph.

It uses two indexes,
	
	1. disc[v]   determines the discovery time of a vertex
	
	2. low[v]    determines the low time for the vertex

Depth First search(DFS) is used for searching.

## Example

![untitled1](https://user-images.githubusercontent.com/13069229/35493079-4ad31694-0476-11e8-9f85-7cdf4d5ed0c6.jpg)

![untitled2](https://user-images.githubusercontent.com/13069229/35493111-8c0a4d30-0476-11e8-80a9-f0518fa6cb29.jpg)

![untitled3](https://user-images.githubusercontent.com/13069229/35493115-92309610-0476-11e8-91aa-5081968ba692.jpg)

The time complexity for Tarjan’s strongly connected components is time bound linear in V and E.

Tarjan uses only one DFS which makes it more faster
