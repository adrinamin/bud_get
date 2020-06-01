from flask_assets import Environment, Bundle
from flask import Flask


def initialize_scss(app: Flask):
    """
    https://stackoverflow.com/questions/48402360/cant-generate-all-css-file-from-sass-files-with-flask-assets
    https://github.com/miracle2k/flask-assets
    https://flask-assets.readthedocs.io/en/latest/
    """
    assets = Environment(app)
    assets.url = app.static_url_path
    assets.debug = True

    scsss = Bundle("./scss/site.scss", filters="pyscss", output="gen/all.css")
    assets.register("scss_all", scsss)