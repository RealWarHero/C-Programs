def is_complete_graph(graph,num_vertices):
    for i in range(num_vertices):
        for j in range(num_vertices):
            if i!=j and graph[i][j]!=1:
                return False
    return True

#main
graph = {}
num_vertices = int(input("Enter the number of vertices in the graph : "))
print('\nNote:Here whole numbers are used to represent the vertices\n')
print("Enter the graph in aadjacency list : \n")
for i in range(num_vertices):
    vertex = input(f'Enter the vertices connected to vertex {i} (seperated by commas) : ')
    vertices = [int(v) for v in vertex.split(",")]
    graph[i] = vertices
print("\nAdjacency Matrix representation : \n")
for vertex,neighbors in graph.items():
    print(f'{vertex} : {neighbors}')
if(is_complete_graph(graph,num_vertices)):
    print("The graph is a complete graph.")
else:
    print("The graph is not a complete graph.")