for i in range(12):
	s = input()
	print('cd ./{}'.format(s))
	print('/Library/TeX/texbin/xelatex -interaction nonstopmode -halt-on-error -file-line-error problem.tex')
	print('cd ..')
