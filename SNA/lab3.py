import networkx as nx
import matplotlib.pyplot as plt
import numpy as np
from scipy.integrate import odeint

# Load the dataset (e.g., Karate dataset)
G = nx.karate_club_graph()

# Define the epidemic models
def SIR_model(y, t, beta, gamma):
    S, I, R = y
    dSdt = -beta * S * I
    dIdt = beta * S * I - gamma * I
    dRdt = gamma * I
    return dSdt, dIdt, dRdt

def SI_model(y, t, beta):
    S, I = y
    dSdt = -beta * S * I
    dIdt = beta * S * I
    return dSdt, dIdt

def Linear_Cascade_model(y, t, beta, alpha):
    x = y
    dxdt = -beta * x + alpha * np.dot(G.adj, x)
    return dxdt

# Define the initial conditions
I0 = 1
R0 = 0
S0 = len(G.nodes) - I0 - R0

# Define the time vector
t = np.linspace(0, 50, 1000)

# Solve the ODEs for each epidemic model
# SIR model
beta = 0.2
gamma = 0.1
sol_SIR = odeint(SIR_model, [S0, I0, R0], t, args=(beta, gamma))
S_SIR = sol_SIR[:, 0]
I_SIR = sol_SIR[:, 1]
R_SIR = sol_SIR[:, 2]

# SI model
beta = 0.2
sol_SI = odeint(SI_model, [S0, I0], t, args=(beta,))
S_SI = sol_SI[:, 0]
I_SI = sol_SI[:, 1]

# Linear Cascade model
beta = 0.2
alpha = 0.1
x0 = np.zeros(len(G.nodes))
x0[0] = I0
sol_Linear_Cascade = odeint(Linear_Cascade_model, x0, t, args=(beta, alpha))
I_Linear_Cascade = sol_Linear_Cascade[:, 0]

# Plot the results
plt.plot(t, S_SIR, label='SIR (S)')
plt.plot(t, I_SIR, label='SIR (I)')
plt.plot(t, R_SIR, label='SIR (R)')
plt.plot(t, S_SI, label='SI (S)')
plt.plot(t, I_SI, label='SI (I)')
plt.plot(t, I_Linear_Cascade, label='Linear Cascade (I)')
plt.legend()
plt.show()
