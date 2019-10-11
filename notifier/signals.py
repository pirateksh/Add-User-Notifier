from django.contrib.auth.models import User
from django.db.models.signals import post_save
from django.dispatch import receiver

# Channels layer is like common communication channel for all instances.
from channels.layers import get_channel_layer

# We will use this layer in a synchronous code, so, we need to convert async to sync.
from asgiref.sync import async_to_sync

@receiver(post_save, sender=User)
def announce_new_user(sender, instance, created, **kwargs):
	# This signal passes(broadcasts) message to the consumer when a new user is created.
	if created:
		channel_layer = get_channel_layer()

		# group_send is for broadcast purposes.
		# async_to_sync is a wrapper used around asynchronous function group_send.
		async_to_sync(channel_layer.group_send)(
			# First argument 'gossip' is name of the group (chosen by us)
			"gossip", {
				"type": "user.gossip",  # . will be converted to _ when handled by consumer.
				"event": "New User",  # Name of event.
				"username": instance.username,  # Username of user who just got created.
			}
		)