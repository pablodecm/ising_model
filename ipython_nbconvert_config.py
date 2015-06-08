c = get_config()

c.NbConvertApp.notebooks = ['IsingModel.ipynb']
c.NbConvertApp.export_format = 'pdf'

c.Exporter.template_file = 'IsingModel'
