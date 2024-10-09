import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

x = np.array([11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31])
y = np.array([1,1,2,4,7,15,31,64,127,254,514,1018,2042,4078,8145,16305,32600,65108,130253,260390,522141])


ly = np.log2(y)

plt.scatter(x,ly)



model = LinearRegression().fit(x.reshape(-1,1),ly)
print('slope:',model.coef_)

plt.scatter(x,ly)
plt.plot(x,model.intercept_ + model.coef_ * x, 'r')
plt.show()

import statsmodels.api as sm
x = sm.add_constant(x)
res = sm.OLS(ly,x).fit()
print('slope conf interval: ', res.conf_int(0.05)[1])
