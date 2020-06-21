from flask import Flask
from scss_compiler_wrapper import initialize_scss


def create_app(config=None, environment=None):
    app = Flask(__name__, instance_relative_config=True)

    initialize_scss(app)

    # inizialize db
    # check configs

    # if test_config is None:
    #     # load the instance config, if it exists, when not testing
    #     app.config.from_pyfile('config.py', silent=True)
    # else:
    #     # load the test config if passed in
    #     app.config.from_mapping(test_config)

    # ensure the instance folder exists
    # try:
    #     os.makedirs(app.instance_path)
    # except OSError:
    #     pass
    
    from accounts import account_bp

    app.register_blueprint(account_bp)
    
    return app