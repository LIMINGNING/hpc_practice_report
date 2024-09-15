import matplotlib.pyplot as plt
plt.rcParams.update({'font.size': 15})

fig, ax = plt.subplots(figsize=(15, 10))
x = [8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192]
gflops_naive  = [3.413333e-01, 4.551111e-01, 4.714820e-01, 4.431851e-01, 4.537326e-01, 4.360380e-01, 3.884334e-01, 3.455149e-01, 1.616524e-01, 1.316193e-01, 1.250629e-01]
gflops_cblas  = [3.394100e-04, 8.192000e+00, 1.638400e+01, 3.744914e+01, 4.152776e+01, 6.190855e+01, 6.832157e+01, 8.340390e+01, 7.595427e+01, 7.357325e+01, 6.301732e+01]
gflops_openmp = [3.785162e-05, 7.550230e-03, 1.927529e+00, 9.362286e+00, 5.899162e+00, 2.649801e+00, 6.645923e+00, 6.213676e+00, 5.013859e+00, 1.616677e+00, 1.364728e+00]
gflops_pthreads = [5.120000e-01, 1.747813e-03, 1.514233e-02, 9.685720e-02, 7.464503e-01, 2.550310e+00, 5.529052e+00, 6.302763e+00, 4.016560e+00, 1.818699e+00, 1.542017e+00]

plt.plot(x, gflops_naive, label='naive', color='blue', linestyle='-', linewidth=3.0)
plt.plot(x, gflops_cblas, label='cblas', color='green', linestyle='-.', linewidth=3.0)
plt.plot(x, gflops_openmp, label='openmp', color='purple', linestyle=':', linewidth=3.0)
plt.plot(x, gflops_pthreads, label='pthreads', color='red', linestyle=':', linewidth=3.0)

plt.title('dgemm')
plt.xlabel('matrix size')
plt.ylabel('gflops')
plt.legend()

# plt.savefig('result.png')
plt.show()