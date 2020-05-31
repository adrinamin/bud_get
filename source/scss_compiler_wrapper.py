from flask_assets import Environment, Bundle
from flask import Flask


def initialize_scss(app: Flask):
    assets = Environment(app)
    assets.url = app.static_url_path
    assets.debug = True

    scsss = Bundle("./scss/site.scss", filters="pyscss", output="gen/all.css")
    assets.register("scss_all", scsss)