import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

x = np.array([400,800,1600,3200,6400,12800,25600,51200,102400,204800,409600])
y = np.array([1,2,10,41,167,672,2683,10745,43017,172129,688239])

lx = np.log2(x)
ly = np.log2(y)

plt.scatter(lx,ly)



model = LinearRegression().fit(lx.reshape(-1,1),ly)
print('slope:',model.coef_)

plt.scatter(lx,ly)
plt.plot(lx,model.intercept_ + model.coef_ * lx, 'r')
plt.show()

import statsmodels.api as sm
lx = sm.add_constant(lx)
res = sm.OLS(ly,lx).fit()
print('slope conf interval: ', res.conf_int(0.05)[1])
