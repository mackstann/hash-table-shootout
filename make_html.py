import sys
html_template = file('charts-template.html', 'r').read()
file('charts.html', 'w').write(html_template.replace('__CHART_DATA_GOES_HERE__', sys.stdin.read()))
