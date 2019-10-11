from django.apps import AppConfig


class NotifierConfig(AppConfig):
    name = 'notifier'

    # For using signals.

    def ready(self):
    	from . import signals
