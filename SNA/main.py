import networkx as nx
import csv
import matplotlib.pyplot as plt

g=nx.karate_club_graph()
# g=nx.Graph()
# with open("dolphins.csv", mode ='r')as file:
#     csvFile = csv.DictReader(file)
#     for row in csvFile:
#         g.add_edge(int(row['Source'])-1,int(row['Target'])-1)

# g=nx.Graph()
# with open("football.csv", mode ='r')as file:
#     csvFile = csv.DictReader(file)
#     for row in csvFile:
#         g.add_edge(int(row['Source'])-1,int(row['Target'])-1)

degree_centrality=nx.degree_centrality(g)
closeness_centrality=nx.closeness_centrality(g)
betweenness_centrality=nx.betweenness_centrality(g)


print("------------------------")
print("Degree centrality: \n", degree_centrality)
print("Closeness centrality: \n",closeness_centrality)
print("Betweenness centrality: \n",betweenness_centrality)


plt.figure(figsize=(15,15))
nx.draw_networkx(g, with_labels=True)
plt.show()