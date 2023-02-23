import matplotlib.pyplot as plt
import networkx as nx      

g = nx.erdos_renyi_graph(100, 0.04)
nx.draw_networkx(g)
plt.show()

g = nx.barabasi_albert_graph(50, 10)
nx.draw_networkx(g)
plt.show()


g = nx.LFR_benchmark_graph(n=250, tau1=3, tau2=1.5,
                            mu=0.1, average_degree=5, min_community=20, seed=10)
nx.draw_networkx(g)
plt.show()