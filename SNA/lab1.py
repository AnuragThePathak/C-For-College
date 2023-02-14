import networkx as nx
import csv
import matplotlib.pyplot as plt


def assign_color(c, level):
    if c < level:
        return "#9b0000"
    elif c < 2 * level:
        return "#9b6000"
    return "#9b60b7"


g = nx.karate_club_graph()
# g = nx.Graph()
# with open("dolphins.csv", mode='r') as file:
#     csvFile = csv.DictReader(file)
#     for row in csvFile:
#         g.add_edge(int(row['Source']) - 1, int(row['Target']) - 1)

# g=nx.Graph()
# with open("football.csv", mode='r')as file:
#     csvFile = csv.DictReader(file)
#     for row in csvFile:
#         g.add_edge(int(row['Source'])-1,int(row['Target'])-1)

degree_centrality = nx.degree_centrality(g)
m = max(degree_centrality.values())
low = m / 3
degree_size = []
degree_color = []
for i in degree_centrality.values():
    degree_size.append(50 + 1000 * i)
    degree_color.append(assign_color(i, low))

plt.subplot(3, 1, 1)
plt.title("Degree Centrality")
nx.draw_networkx(g, with_labels=True, node_size=degree_size, font_size=8, node_color=degree_color)

closeness_centrality = nx.closeness_centrality(g)
m = max(closeness_centrality.values())
low = m / 3
closeness_size = []
closeness_color = []
for i in closeness_centrality.values():
    closeness_size.append(50 + 1000 * i)
    closeness_color.append(assign_color(i, low))

plt.subplot(3, 1, 2)
plt.title("Closeness Centrality")
nx.draw_networkx(g, with_labels=True, node_size=closeness_size, font_size=8, node_color=closeness_color)

betweenness_centrality = nx.betweenness_centrality(g)
m = max(degree_centrality.values())
low = m / 3
betweenness_size = []
betweenness_color = []
for i in betweenness_centrality.values():
    betweenness_size.append(150 + 1000 * i)
    betweenness_color.append(assign_color(i, low))

plt.subplot(3, 1, 3)
plt.title("Betweenness Centrality")
nx.draw_networkx(g, with_labels=True, node_size=betweenness_size, font_size=8, node_color=betweenness_color)

print("------------------------")
print("Degree centrality: \n", degree_centrality)
print("Closeness centrality: \n", closeness_centrality)
print("Betweenness centrality: \n", betweenness_centrality)

plt.show()
