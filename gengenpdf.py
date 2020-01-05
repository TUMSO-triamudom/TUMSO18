for i in range(12):
	s = input()
	print('cd ./{}'.format(s))
	print('/Library/TeX/texbin/xelatex -interaction nonstopmode  problem.tex')
	print('cd ..')
